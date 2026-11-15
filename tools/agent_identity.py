"""Record attribution before work starts, without guessing an external contributor's model."""
import re
import profiles


def named(value):
    return isinstance(value, str) and bool(value.strip()) and not any(ord(c) < 32 for c in value) and value.strip().lower() not in ('?', 'unknown', 'unrecorded', 'not reported')


def resolve(model=None, agent=None, profile=None, tier='first', drafted_by=None):
    if model is not None:
        if not named(model):
            raise ValueError('model must name the actual model; pass --model <actual-model>')
        return model.strip()
    if named(drafted_by):
        return drafted_by.strip()
    if named(agent):
        return re.sub(r'-\d+$', '', agent.strip())
    if profile:
        return profiles.role(profile, 'drafter' if tier == 'first' else 'drafter_' + tier)['model']
    raise ValueError('model or agent is required before work starts; pass --model <actual-model> or --agent <name>')
