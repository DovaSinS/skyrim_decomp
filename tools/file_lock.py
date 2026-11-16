"""Advisory file locks with kernel-owned lifetime on POSIX and Windows.

The locked byte is beyond the file contents, so locks never change JSON or log payloads.
Windows LockFileEx, like flock, permits probing an empty file without writing to it.
"""
import os

if os.name != 'nt':
    from fcntl import LOCK_EX, LOCK_SH, LOCK_NB, LOCK_UN, flock
else:
    import ctypes
    from ctypes import wintypes
    import msvcrt

    LOCK_SH, LOCK_EX, LOCK_NB, LOCK_UN = 1, 2, 4, 8

    class Overlapped(ctypes.Structure):
        _fields_ = [('Internal', ctypes.c_size_t), ('InternalHigh', ctypes.c_size_t),
                    ('Offset', wintypes.DWORD), ('OffsetHigh', wintypes.DWORD),
                    ('hEvent', wintypes.HANDLE)]

    kernel = ctypes.WinDLL('kernel32', use_last_error=True)
    kernel.LockFileEx.argtypes = [wintypes.HANDLE, wintypes.DWORD, wintypes.DWORD,
                                 wintypes.DWORD, wintypes.DWORD, ctypes.POINTER(Overlapped)]
    kernel.LockFileEx.restype = wintypes.BOOL
    kernel.UnlockFileEx.argtypes = [wintypes.HANDLE, wintypes.DWORD, wintypes.DWORD,
                                   wintypes.DWORD, ctypes.POINTER(Overlapped)]
    kernel.UnlockFileEx.restype = wintypes.BOOL

    def flock(file, operation):
        fd = file if isinstance(file, int) else file.fileno()
        handle = msvcrt.get_osfhandle(fd)
        overlapped = Overlapped(Offset=0xffffffff, OffsetHigh=0x7fffffff)
        if operation == LOCK_UN:
            ok = kernel.UnlockFileEx(handle, 0, 1, 0, ctypes.byref(overlapped))
        else:
            flags = (1 if operation & LOCK_NB else 0) | (2 if operation & LOCK_EX else 0)
            ok = kernel.LockFileEx(handle, flags, 0, 1, 0, ctypes.byref(overlapped))
        if not ok:
            code = ctypes.get_last_error()
            if code in (32, 33, 158):
                raise BlockingIOError(code, 'file lock is held')
            raise ctypes.WinError(code)
