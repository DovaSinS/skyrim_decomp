#!/usr/bin/env python3
"""Refresh public contributor-target boundaries locally; never publishes function bytes/names.

Only claim URLs/scopes and boundary metadata leave this command. The image stays local and is
hash checked. Private function-table input is resolved only for the pinned build's open claims.
"""
import argparse
import datetime as dt
import json
from pathlib import Path
import sys

import contrib
from pecoff import PeImage
import target_hashes as hashes

ROOT=Path(__file__).resolve().parents[1]


def collect(root, image_bytes, function_table, claims):
    target=contrib.target_manifest(root)
    if hashes.digest(image_bytes)!=target['image_sha256']:
        raise ValueError('image differs from pinned build')
    progress=contrib.inventory(root)
    known={f['rva']:f for f in progress['functions']}
    metadata={f['rva']:f for f in map(json.loads,function_table.read_text().splitlines())}
    image=PeImage(image_bytes);pdata={a:b-a for a,b,_ in image.runtime_functions()}
    selected=[c for c in claims if not c.get('pull_request') and c.get('build_id')==target['build_id']]
    wanted=set()
    for claim in selected:
        for a,b in claim.get('entries',[]):
            wanted.update([a] if b==a+1 else [r for r in metadata if a<=r<b])
    next_={contrib.parse_rva(c['rva']) for c in contrib.candidates(root,progress) if c['startable']}
    rows=[];unresolved=[]
    for rva in sorted((wanted|next_)-known.keys()):
        fn=metadata.get(rva)
        if fn and fn.get('size',0)>0:size,source=fn['size'],'local-function-table'
        elif rva in pdata:size,source=pdata[rva],'single-pdata-entry'
        else:unresolved.append(rva);continue
        image.read(rva,size,'offered target boundary')
        rows.append(dict(rva=rva,size=size,extent_source=source))
    if unresolved:
        raise ValueError('claim boundaries unresolved; nothing published')
    return dict(schema=1,build_id=target['build_id'],snapshot_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        function_metadata_sha256=hashes.digest(function_table.read_bytes()),
        claims_snapshot_sha256=hashes.digest(json.dumps(claims,sort_keys=True).encode()),
        claims=[dict(number=c['number'],url=c['url'],entries=c['entries']) for c in selected],
        next_candidate_count=len(next_),claim_function_count=len(wanted),functions=rows,unresolved_rvas=[])


def main(argv=None):
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--image',type=Path,required=True)
    p.add_argument('--function-table',type=Path,required=True)
    a=p.parse_args(argv)
    ctx=contrib.Ctx(repo=ROOT,interactive=False)
    index=ctx.github().open_items(refresh=True)
    output=collect(ROOT,a.image.read_bytes(),a.function_table,index.records)
    (ROOT/hashes.OFFERED).write_text(json.dumps(output,indent=2)+'\n')
    print(json.dumps(dict(extra_targets=len(output['functions']),next_candidates=output['next_candidate_count'],
                          claims=len(output['claims']),acceptance='not-evaluated')))
    return 0


if __name__=='__main__':sys.exit(main())
