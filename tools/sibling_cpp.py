"""Namespace-aware lexical C++ body parser, reused from the private p127 study."""
import re
import check_origin as co

def functions(text):
    pairs=co.brace_pairs(text);out=[]
    def walk(lo,hi,scope=(),templated=False):
        seg=i=lo
        while True:
            m=re.compile(r'[{};]').search(text,i,hi)
            if not m:return
            pos=m.start()
            if m.group()!='{':seg=i=pos+1;continue
            end=pairs.get(pos,hi);head=text[seg:pos]
            plain=co.untemplate(co.ACCESS.sub(' ',head)).strip()
            if re.search(r'\benum\b',plain):pass
            elif re.search(r'\bnamespace\b',plain) and '(' not in plain:
                ns=re.search(r'\bnamespace\s+([A-Za-z_]\w*(?:::[A-Za-z_]\w*)*)',plain)
                walk(pos+1,end,scope+tuple(ns[1].split('::')) if ns else scope+('(anonymous)',),templated)
            elif re.search(r'\bextern\s*"',plain) and '(' not in plain:walk(pos+1,end,scope,templated)
            elif co.CLASS_HEAD.search(plain):
                cls=co.CLASS_HEAD.search(plain).group(2)
                walk(pos+1,end,scope+(cls,),templated or bool(re.search(r'\btemplate\s*<',head)))
            else:
                found=co.function_head(head)
                if found and found[2]:i=end+1;continue
                if found and not templated:
                    name,params,_=found
                    name=re.sub(r'operator_([0-9a-f]+)',lambda o:'operator'+bytes.fromhex(o[1]).decode(),name)
                    parts=name.split('::')
                    # Fully qualified out-of-line names remain intact; relative definitions inherit namespace.
                    if scope and parts[:len(scope)]!=list(scope):parts=list(scope)+parts
                    qual='::'.join(parts)
                    if len(parts)>1 and '(anonymous)' not in parts and not re.search(r'\w+\s*<[^;{}]*>\s*::|\btemplate\s*<',head):
                        out.append({'class':'::'.join(parts[:-1]),'name':parts[-1],'qualified':qual,
                                    'line':text.count('\n',0,pos)+1,'params':co.parameters(params),
                                    'body':text[pos+1:end],'head':co.ACCESS.sub(' ',head),
                                    'start':pos,'end':end})
            seg=i=end+1
    walk(0,len(text))
    return out
