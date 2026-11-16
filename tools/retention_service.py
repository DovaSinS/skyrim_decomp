"""Run the existing private retention lifecycle once from an ignored scheduler config."""
import argparse
import json
import glob
from pathlib import Path

import flow_cleanup
import staged_exports


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--config', type=Path, required=True)
    args = parser.parse_args()
    config = json.loads(args.config.read_text())
    root, fdir = Path(config['repository']).resolve(), Path(config['flow_dir']).resolve()
    exports = []
    for pattern in config.get('export_roots', [str(root)]):
        for path in glob.glob(pattern):
            exports.extend(staged_exports.reap(Path(path)))
    print(json.dumps(dict(exports=exports, retention=flow_cleanup.automatic_retention(root, fdir, offload=True)), indent=2))


if __name__ == '__main__':
    main()
