# main.py

import ctypes
import os
import platform

# Determine library extension based on your OS.
lib_suffix = ""
if platform.system() == "Windows":
    lib_suffix = "dll"
elif platform.system() == "Darwin":
    lib_suffix = "dylib"
else:
    lib_suffix = "so"

lib_name = f"../rust_ffi/target/debug/librust_ffi.{lib_suffix}"

# Load the shared library
rust_lib = ctypes.CDLL(lib_name)

# Define the result type and argument types of the function `add`
rust_lib.add.restype = ctypes.c_int
rust_lib.add.argtypes = [ctypes.c_int, ctypes.c_int]

# Call the function `add`
result = rust_lib.add(35, 34)  # 69

print(f"Result from external addition of 35 and 34: {result}")
