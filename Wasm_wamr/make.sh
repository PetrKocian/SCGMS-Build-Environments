#!/bin/bash

# Copyright (C) 2019 Intel Corporation.  All rights reserved.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

rm -rf build
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=wasi_toolchain.cmake
make



echo "Generate test_wasm.h .."
../binarydump -o test_wasm.h -n wasm_test_file scgms

echo "Done"

sed -i 's/__aligned(4) //g' test_wasm.h

cp test_wasm.h ~/Desktop/WebAssembly_wamr_build_demo/sources/scgms/filters/modify_filter/src
