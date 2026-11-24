```shell
NAME=demo
g++ -o Release/obj.target/$NAME/src/$NAME.o ../src/$NAME.cc '-DNODE_GYP_MODULE_NAME=$NAME' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_GLIBCXX_USE_CXX11_ABI=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-D__STDC_FORMAT_MACROS' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DBUILDING_NODE_EXTENSION' -I/home/andrew/.cache/node-gyp/23.0.0/include/node -I/home/andrew/.cache/node-gyp/23.0.0/src -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/config -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/openssl/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/uv/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/zlib -I/home/andrew/.cache/node-gyp/23.0.0/deps/v8/include  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -O3 -fno-omit-frame-pointer -fno-rtti -fno-exceptions -fno-strict-aliasing -std=gnu++20 -O3 -march=native -mtune=native -MMD -MF ./Release/.deps/Release/obj.target/$NAME/src/$NAME.o.d.raw -c
g++ -o Release/obj.target/$NAME.node -shared -pthread -rdynamic -m64  -Wl,-soname=$NAME.node -Wl,--start-group Release/obj.target/$NAME/src/$NAME.o -Wl,--end-group 
```

```shell
gyp info it worked if it ends with ok
gyp verb cli [
gyp verb cli '/home/andrew/.node/23/bin/node',
gyp verb cli '/home/andrew/.node/23/bin/node-gyp',
gyp verb cli '--verbose',
gyp verb cli 'rebuild'
gyp verb cli ]
gyp info using node-gyp@11.0.0
gyp info using node@23.0.0 | linux | x64
gyp verb clean removing "build" directory
gyp verb find Python Python is not set from command line or npm configuration
gyp verb find Python Python is not set from environment variable PYTHON
gyp verb find Python checking if "python3" can be used
gyp verb find Python - executing "python3" to get executable path
gyp verb find Python - executable path is "/usr/bin/python3"
gyp verb find Python - executing "/usr/bin/python3" to get version
gyp verb find Python - version is "3.10.12"
gyp info find Python using Python version 3.10.12 found at "/usr/bin/python3"
gyp verb get node dir no --target version specified, falling back to host node version: 23.0.0

gyp verb install input version string "23.0.0"
gyp verb install installing version: 23.0.0
gyp verb install --ensure was passed, so won't reinstall if already installed
gyp verb install version is already installed, need to check "installVersion"
gyp verb got "installVersion" 11
gyp verb needs "installVersion" 11
gyp verb install version is good
gyp verb get node dir target node version installed: 23.0.0
gyp verb build dir attempting to create "build" dir: /media/andrew/OCZ/source2023/just-js/node-lo/build
gyp verb build dir "build" dir needed to be created? Yes
gyp verb build/config.gypi creating config file
gyp verb build/config.gypi writing out config file: /media/andrew/OCZ/source2023/just-js/node-lo/build/config.gypi
gyp verb config.gypi checking for gypi file: /media/andrew/OCZ/source2023/just-js/node-lo/config.gypi
gyp verb common.gypi checking for gypi file: /media/andrew/OCZ/source2023/just-js/node-lo/common.gypi
gyp verb gyp gyp format was not specified; forcing "make"
gyp info spawn /usr/bin/python3
gyp info spawn args [
gyp info spawn args '/home/andrew/.node/23/lib/node_modules/node-gyp/gyp/gyp_main.py',
gyp info spawn args 'binding.gyp',
gyp info spawn args '-f',
gyp info spawn args 'make',
gyp info spawn args '-I',
gyp info spawn args '/media/andrew/OCZ/source2023/just-js/node-lo/build/config.gypi',
gyp info spawn args '-I',
gyp info spawn args '/home/andrew/.node/23/lib/node_modules/node-gyp/addon.gypi',
gyp info spawn args '-I',
gyp info spawn args '/home/andrew/.cache/node-gyp/23.0.0/include/node/common.gypi',
gyp info spawn args '-Dlibrary=shared_library',
gyp info spawn args '-Dvisibility=default',
gyp info spawn args '-Dnode_root_dir=/home/andrew/.cache/node-gyp/23.0.0',
gyp info spawn args '-Dnode_gyp_dir=/home/andrew/.node/23/lib/node_modules/node-gyp',
gyp info spawn args '-Dnode_lib_file=/home/andrew/.cache/node-gyp/23.0.0/<(target_arch)/node.lib',
gyp info spawn args '-Dmodule_root_dir=/media/andrew/OCZ/source2023/just-js/node-lo',
gyp info spawn args '-Dnode_engine=v8',
gyp info spawn args '--depth=.',
gyp info spawn args '--no-parallel',
gyp info spawn args '--generator-output',
gyp info spawn args 'build',
gyp info spawn args '-Goutput_dir=.'
gyp info spawn args ]
gyp verb build type Release
gyp verb architecture x64
gyp verb node dev dir /home/andrew/.cache/node-gyp/23.0.0
gyp verb python /usr/bin/python3
gyp verb `which` succeeded for `make` /usr/bin/make
gyp verb bin symlinks created symlink to "/usr/bin/python3" in "/media/andrew/OCZ/source2023/just-js/node-lo/build/node_gyp_bins" and added to PATH
gyp info spawn make
gyp info spawn args [ 'V=1', 'BUILDTYPE=Release', '-C', 'build' ]
make: Entering directory '/media/andrew/OCZ/source2023/just-js/node-lo/build'
  g++ -o Release/obj.target/count/src/count.o ../src/count.cc '-DNODE_GYP_MODULE_NAME=count' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_GLIBCXX_USE_CXX11_ABI=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-D__STDC_FORMAT_MACROS' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DBUILDING_NODE_EXTENSION' -I/home/andrew/.cache/node-gyp/23.0.0/include/node -I/home/andrew/.cache/node-gyp/23.0.0/src -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/config -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/openssl/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/uv/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/zlib -I/home/andrew/.cache/node-gyp/23.0.0/deps/v8/include  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -O3 -fno-omit-frame-pointer -fno-rtti -fno-exceptions -fno-strict-aliasing -std=gnu++20 -O3 -march=native -mtune=native -MMD -MF ./Release/.deps/Release/obj.target/count/src/count.o.d.raw   -c
In file included from ../src/ffast.h:1,
                 from ../src/count.cc:2:
/home/andrew/.cache/node-gyp/23.0.0/include/node/node.h:1232:7: warning: cast between incompatible function types from ‘void (*)(v8::Local<v8::Object>)’ to ‘node::addon_register_func’ {aka ‘void (*)(v8::Local<v8::Object>, v8::Local<v8::Value>, void*)’} [-Wcast-function-type]
 1232 |       (node::addon_register_func) (regfunc),                          \
      |       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/andrew/.cache/node-gyp/23.0.0/include/node/node.h:1266:3: note: in expansion of macro ‘NODE_MODULE_X’
 1266 |   NODE_MODULE_X(modname, regfunc, NULL, 0)  // NOLINT (readability/null_usage)
      |   ^~~~~~~~~~~~~
../src/count.cc:116:1: note: in expansion of macro ‘NODE_MODULE’
  116 | NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
      | ^~~~~~~~~~~
  g++ -o Release/obj.target/count.node -shared -pthread -rdynamic -m64  -Wl,-soname=count.node -Wl,--start-group Release/obj.target/count/src/count.o -Wl,--end-group 
  ln -f "Release/obj.target/count.node" "Release/count.node" 2>/dev/null || (rm -rf "Release/count.node" && cp -af "Release/obj.target/count.node" "Release/count.node")
  g++ -o Release/obj.target/demo/src/demo.o ../src/demo.cc '-DNODE_GYP_MODULE_NAME=demo' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_GLIBCXX_USE_CXX11_ABI=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-D__STDC_FORMAT_MACROS' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DBUILDING_NODE_EXTENSION' -I/home/andrew/.cache/node-gyp/23.0.0/include/node -I/home/andrew/.cache/node-gyp/23.0.0/src -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/config -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/openssl/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/uv/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/zlib -I/home/andrew/.cache/node-gyp/23.0.0/deps/v8/include  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -O3 -fno-omit-frame-pointer -fno-rtti -fno-exceptions -fno-strict-aliasing -std=gnu++20 -O3 -march=native -mtune=native -MMD -MF ./Release/.deps/Release/obj.target/demo/src/demo.o.d.raw   -c
In file included from ../src/ffast.h:1,
                 from ../src/demo.cc:2:
/home/andrew/.cache/node-gyp/23.0.0/include/node/node.h:1232:7: warning: cast between incompatible function types from ‘void (*)(v8::Local<v8::Object>)’ to ‘node::addon_register_func’ {aka ‘void (*)(v8::Local<v8::Object>, v8::Local<v8::Value>, void*)’} [-Wcast-function-type]
 1232 |       (node::addon_register_func) (regfunc),                          \
      |       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/andrew/.cache/node-gyp/23.0.0/include/node/node.h:1266:3: note: in expansion of macro ‘NODE_MODULE_X’
 1266 |   NODE_MODULE_X(modname, regfunc, NULL, 0)  // NOLINT (readability/null_usage)
      |   ^~~~~~~~~~~~~
../src/demo.cc:56:1: note: in expansion of macro ‘NODE_MODULE’
   56 | NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
      | ^~~~~~~~~~~
  g++ -o Release/obj.target/demo.node -shared -pthread -rdynamic -m64  -Wl,-soname=demo.node -Wl,--start-group Release/obj.target/demo/src/demo.o -Wl,--end-group 
  ln -f "Release/obj.target/demo.node" "Release/demo.node" 2>/dev/null || (rm -rf "Release/demo.node" && cp -af "Release/obj.target/demo.node" "Release/demo.node")
  g++ -o Release/obj.target/ffast/src/ffast.o ../src/ffast.cc '-DNODE_GYP_MODULE_NAME=ffast' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_GLIBCXX_USE_CXX11_ABI=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-D__STDC_FORMAT_MACROS' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DBUILDING_NODE_EXTENSION' -I/home/andrew/.cache/node-gyp/23.0.0/include/node -I/home/andrew/.cache/node-gyp/23.0.0/src -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/config -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/openssl/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/uv/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/zlib -I/home/andrew/.cache/node-gyp/23.0.0/deps/v8/include  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -O3 -fno-omit-frame-pointer -fno-rtti -fno-exceptions -fno-strict-aliasing -std=gnu++20 -O3 -march=native -mtune=native -MMD -MF ./Release/.deps/Release/obj.target/ffast/src/ffast.o.d.raw   -c
../src/ffast.cc: In function ‘void ffast::lo_callback(ffast::exec_info*)’:
../src/ffast.cc:211:33: warning: ignoring return value of ‘v8::MaybeLocal<v8::Value> v8::Function::Call(v8::Local<v8::Context>, v8::Local<v8::Value>, int, v8::Local<v8::Value>*)’, declared with attribute ‘warn_unused_result’ [-Wunused-result]
  211 |   info->js_fn.Get(isolate)->Call(isolate->GetCurrentContext(),
      |   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  212 |     v8::Null(isolate), 0, 0);
      |     ~~~~~~~~~~~~~~~~~~~~~~~~     
In file included from /home/andrew/.cache/node-gyp/23.0.0/include/node/v8.h:33,
                 from /home/andrew/.cache/node-gyp/23.0.0/include/node/node.h:73,
                 from ../src/ffast.h:1,
                 from ../src/ffast.cc:2:
/home/andrew/.cache/node-gyp/23.0.0/include/node/v8-function.h:59:43: note: declared here
   59 |   V8_WARN_UNUSED_RESULT MaybeLocal<Value> Call(Local<Context> context,
      |                                           ^~~~
../src/ffast.cc: In function ‘void ffast::SlowCallback(const v8::FunctionCallbackInfo<v8::Value>&)’:
../src/ffast.cc:285:21: warning: suggest parentheses around comparison in operand of ‘&’ [-Wparentheses]
  285 |   if (state->nparam == 0 & state->result == FastTypes::empty) {
      |       ~~~~~~~~~~~~~~^~~~
../src/ffast.cc: In function ‘void ffast::unwrap_memorySlow(const v8::FunctionCallbackInfo<v8::Value>&)’:
../src/ffast.cc:508:13: warning: ‘void v8::ArrayBuffer::Detach()’ is deprecated: Use the version which takes a key parameter (passing a null handle is ok). [-Wdeprecated-declarations]
  508 |   ab->Detach();
      |   ~~~~~~~~~~^~
In file included from /home/andrew/.cache/node-gyp/23.0.0/include/node/v8.h:24,
                 from /home/andrew/.cache/node-gyp/23.0.0/include/node/node.h:73,
                 from ../src/ffast.h:1,
                 from ../src/ffast.cc:2:
/home/andrew/.cache/node-gyp/23.0.0/include/node/v8-array-buffer.h:306:8: note: declared here
  306 |   void Detach();
      |        ^~~~~~
In file included from ../src/ffast.h:1,
                 from ../src/ffast.cc:2:
../src/ffast.cc: At global scope:
/home/andrew/.cache/node-gyp/23.0.0/include/node/node.h:1232:7: warning: cast between incompatible function types from ‘void (*)(v8::Local<v8::Object>)’ to ‘node::addon_register_func’ {aka ‘void (*)(v8::Local<v8::Object>, v8::Local<v8::Value>, void*)’} [-Wcast-function-type]
 1232 |       (node::addon_register_func) (regfunc),                          \
      |       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/andrew/.cache/node-gyp/23.0.0/include/node/node.h:1266:3: note: in expansion of macro ‘NODE_MODULE_X’
 1266 |   NODE_MODULE_X(modname, regfunc, NULL, 0)  // NOLINT (readability/null_usage)
      |   ^~~~~~~~~~~~~
../src/ffast.cc:749:1: note: in expansion of macro ‘NODE_MODULE’
  749 | NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
      | ^~~~~~~~~~~
  g++ -o Release/obj.target/ffast.node -shared -pthread -rdynamic -m64  -Wl,-soname=ffast.node -Wl,--start-group Release/obj.target/ffast/src/ffast.o -Wl,--end-group 
  ln -f "Release/obj.target/ffast.node" "Release/ffast.node" 2>/dev/null || (rm -rf "Release/ffast.node" && cp -af "Release/obj.target/ffast.node" "Release/ffast.node")
  g++ -o Release/obj.target/libssl/src/libssl.o ../src/libssl.cc '-DNODE_GYP_MODULE_NAME=libssl' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_GLIBCXX_USE_CXX11_ABI=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-D__STDC_FORMAT_MACROS' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DBUILDING_NODE_EXTENSION' -I/home/andrew/.cache/node-gyp/23.0.0/include/node -I/home/andrew/.cache/node-gyp/23.0.0/src -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/config -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/openssl/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/uv/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/zlib -I/home/andrew/.cache/node-gyp/23.0.0/deps/v8/include  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -O3 -fno-omit-frame-pointer -fno-rtti -fno-exceptions -fno-strict-aliasing -std=gnu++20 -O3 -march=native -mtune=native -MMD -MF ./Release/.deps/Release/obj.target/libssl/src/libssl.o.d.raw   -c
In file included from ../src/ffast.h:1,
                 from ../src/libssl.cc:2:
/home/andrew/.cache/node-gyp/23.0.0/include/node/node.h:1232:7: warning: cast between incompatible function types from ‘void (*)(v8::Local<v8::Object>)’ to ‘node::addon_register_func’ {aka ‘void (*)(v8::Local<v8::Object>, v8::Local<v8::Value>, void*)’} [-Wcast-function-type]
 1232 |       (node::addon_register_func) (regfunc),                          \
      |       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/andrew/.cache/node-gyp/23.0.0/include/node/node.h:1266:3: note: in expansion of macro ‘NODE_MODULE_X’
 1266 |   NODE_MODULE_X(modname, regfunc, NULL, 0)  // NOLINT (readability/null_usage)
      |   ^~~~~~~~~~~~~
../src/libssl.cc:2865:1: note: in expansion of macro ‘NODE_MODULE’
 2865 | NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
      | ^~~~~~~~~~~
  g++ -o Release/obj.target/ssl.node -shared -pthread -rdynamic -m64  -Wl,-soname=ssl.node -Wl,--start-group Release/obj.target/libssl/src/libssl.o -Wl,--end-group 
  ln -f "Release/obj.target/ssl.node" "Release/ssl.node" 2>/dev/null || (rm -rf "Release/ssl.node" && cp -af "Release/obj.target/ssl.node" "Release/ssl.node")
  g++ -o Release/obj.target/linecount/src/linecount.o ../src/linecount.cc '-DNODE_GYP_MODULE_NAME=linecount' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_GLIBCXX_USE_CXX11_ABI=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-D__STDC_FORMAT_MACROS' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DBUILDING_NODE_EXTENSION' -I/home/andrew/.cache/node-gyp/23.0.0/include/node -I/home/andrew/.cache/node-gyp/23.0.0/src -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/config -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/openssl/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/uv/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/zlib -I/home/andrew/.cache/node-gyp/23.0.0/deps/v8/include  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -O3 -fno-omit-frame-pointer -fno-rtti -fno-exceptions -fno-strict-aliasing -std=gnu++20 -O3 -march=native -mtune=native -MMD -MF ./Release/.deps/Release/obj.target/linecount/src/linecount.o.d.raw   -c
  g++ -o Release/obj.target/linecount.node -shared -pthread -rdynamic -m64  -Wl,-soname=linecount.node -Wl,--start-group Release/obj.target/linecount/src/linecount.o -Wl,--end-group 
  ln -f "Release/obj.target/linecount.node" "Release/linecount.node" 2>/dev/null || (rm -rf "Release/linecount.node" && cp -af "Release/obj.target/linecount.node" "Release/linecount.node")
  g++ -o Release/obj.target/noop/src/noop.o ../src/noop.cc '-DNODE_GYP_MODULE_NAME=noop' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_GLIBCXX_USE_CXX11_ABI=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-D__STDC_FORMAT_MACROS' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DBUILDING_NODE_EXTENSION' -I/home/andrew/.cache/node-gyp/23.0.0/include/node -I/home/andrew/.cache/node-gyp/23.0.0/src -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/config -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/openssl/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/uv/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/zlib -I/home/andrew/.cache/node-gyp/23.0.0/deps/v8/include  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -O3 -fno-omit-frame-pointer -fno-rtti -fno-exceptions -fno-strict-aliasing -std=gnu++20 -O3 -march=native -mtune=native -MMD -MF ./Release/.deps/Release/obj.target/noop/src/noop.o.d.raw   -c
In file included from ../src/ffast.h:1,
                 from ../src/noop.cc:2:
/home/andrew/.cache/node-gyp/23.0.0/include/node/node.h:1232:7: warning: cast between incompatible function types from ‘void (*)(v8::Local<v8::Object>)’ to ‘node::addon_register_func’ {aka ‘void (*)(v8::Local<v8::Object>, v8::Local<v8::Value>, void*)’} [-Wcast-function-type]
 1232 |       (node::addon_register_func) (regfunc),                          \
      |       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/andrew/.cache/node-gyp/23.0.0/include/node/node.h:1266:3: note: in expansion of macro ‘NODE_MODULE_X’
 1266 |   NODE_MODULE_X(modname, regfunc, NULL, 0)  // NOLINT (readability/null_usage)
      |   ^~~~~~~~~~~~~
../src/noop.cc:44:1: note: in expansion of macro ‘NODE_MODULE’
   44 | NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
      | ^~~~~~~~~~~
  g++ -o Release/obj.target/noop.node -shared -pthread -rdynamic -m64  -Wl,-soname=noop.node -Wl,--start-group Release/obj.target/noop/src/noop.o -Wl,--end-group 
  ln -f "Release/obj.target/noop.node" "Release/noop.node" 2>/dev/null || (rm -rf "Release/noop.node" && cp -af "Release/obj.target/noop.node" "Release/noop.node")
  g++ -o Release/obj.target/tcc/src/tcc.o ../src/tcc.cc '-DNODE_GYP_MODULE_NAME=tcc' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_GLIBCXX_USE_CXX11_ABI=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-D__STDC_FORMAT_MACROS' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DBUILDING_NODE_EXTENSION' -I/home/andrew/.cache/node-gyp/23.0.0/include/node -I/home/andrew/.cache/node-gyp/23.0.0/src -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/config -I/home/andrew/.cache/node-gyp/23.0.0/deps/openssl/openssl/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/uv/include -I/home/andrew/.cache/node-gyp/23.0.0/deps/zlib -I/home/andrew/.cache/node-gyp/23.0.0/deps/v8/include -I../../lo/lib/tcc/deps/libtcc  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -O3 -fno-omit-frame-pointer -fno-rtti -fno-exceptions -fno-strict-aliasing -std=gnu++20 -O3 -march=native -mtune=native -MMD -MF ./Release/.deps/Release/obj.target/tcc/src/tcc.o.d.raw   -c
In file included from ../src/ffast.h:1,
                 from ../src/tcc.cc:2:
/home/andrew/.cache/node-gyp/23.0.0/include/node/node.h:1232:7: warning: cast between incompatible function types from ‘void (*)(v8::Local<v8::Object>)’ to ‘node::addon_register_func’ {aka ‘void (*)(v8::Local<v8::Object>, v8::Local<v8::Value>, void*)’} [-Wcast-function-type]
 1232 |       (node::addon_register_func) (regfunc),                          \
      |       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/andrew/.cache/node-gyp/23.0.0/include/node/node.h:1266:3: note: in expansion of macro ‘NODE_MODULE_X’
 1266 |   NODE_MODULE_X(modname, regfunc, NULL, 0)  // NOLINT (readability/null_usage)
      |   ^~~~~~~~~~~~~
../src/tcc.cc:376:1: note: in expansion of macro ‘NODE_MODULE’
  376 | NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
      | ^~~~~~~~~~~
  g++ -o Release/obj.target/tcc.node -shared -pthread -rdynamic -m64  -Wl,-soname=tcc.node -Wl,--start-group Release/obj.target/tcc/src/tcc.o -Wl,--end-group /media/andrew/OCZ/source2023/just-js/lo/lib/tcc/deps/libtcc/libtcc.a
  ln -f "Release/obj.target/tcc.node" "Release/tcc.node" 2>/dev/null || (rm -rf "Release/tcc.node" && cp -af "Release/obj.target/tcc.node" "Release/tcc.node")
make: Leaving directory '/media/andrew/OCZ/source2023/just-js/node-lo/build'
gyp info ok 
```

## Quick Install & Run (Windows / Linux / macOS)

```sh
# Install globally via awesome-os/pnpm (all platforms)
pnpm add -g github:awesome-os/ffast-experimental

# Run directly (all platforms)
ffast-experimental --help
```
