"""Metadata-versioned wrapper around the unchanged v1/v2 C++ emitters.

The original source headers retain their original emitter provenance. This family
version changes only parameter serialization; it emits exactly those same units.
"""
import hashlib
from pathlib import Path
import represented_field_template_v1 as v1
import represented_field_template_v2 as v2

SOURCE_PINS = {1: '18b4a63c204d6ed9e36f576489c89035882cc10c76a79dbe60ed5ea2e1fa5ecf', 2: 'd32dce69a9cb3105131d364cb4e4543fa5ee03cf23f0284e68e3d0b536b64b75'}


def emitter(version):
    if version not in SOURCE_PINS:
        raise ValueError('unknown original source version')
    module = {1:v1,2:v2}[version]
    if hashlib.sha256(Path(module.__file__).read_bytes()).hexdigest() != SOURCE_PINS[version]:
        raise ValueError('original emitter pin changed')
    return module


def origin(version):
    emitter(version)
    return dict(family='represented-field-leaf', version=f'{version}-metadata2',
                template_digest=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())


def emit(row, version):
    return emitter(version).emit(row)
