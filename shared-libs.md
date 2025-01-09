> a = lo.core.dlopen('libcrypto.so', lo.core.RTLD_LAZY | lo.core.RTLD_LOCAL)
126153671669392
> b = lo.core.dlopen('libcrypto.so', lo.core.RTLD_LAZY | lo.core.RTLD_LOCAL)
126153671669392
> c = lo.core.dlopen('../lo/lib/boringssl/deps/boringssl/build/libcrypto.so', lo.core.RTLD_LAZY | lo.core.RTLD_GLOBAL)
110108973437360
> lo.core.getpid()
738664
> c
110108973437360
> a
126153671669392
> c.toString(16)
6424be3f91b0
> a.toString(16)
72bc70c97690
> bind = (await import('lib/ffi.js')).bind
"bind (...1)"
> handle = new Uint32Array(2)
    0 00 00                                                ..
> aversion = bind(lo.core.dlsym(a, 'OpenSSL_version'), 'pointer', ['i32']) 
" (...1)"
> cversion = bind(lo.core.dlsym(c, 'OpenSSL_version'), 'pointer', ['i32']) 
" (...1)"
> lo.latin1Decode(aversion(1))
compiler: gcc -fPIC -pthread -m64 -Wa,--noexecstack -Wall -Wa,--noexecstack -g -O2 -ffile-prefix-map=/build/openssl-aGUoHt/openssl-3.0.2=. -flto=auto -ffat-lto-objects -flto=auto -ffat-lto-objects -fstack-protector-strong -Wformat -Werror=format-security -DOPENSSL_TLS_SECURITY_LEVEL=2 -DOPENSSL_USE_NODELETE -DL_ENDIAN -DOPENSSL_PIC -DOPENSSL_BUILDING_OPENSSL -DNDEBUG -Wdate-time -D_FORTIFY_SOURCE=2
> lo.latin1Decode(cversion(1))
compiler: n/a
> lo.latin1Decode(aversion(0))
OpenSSL 3.0.2 15 Mar 2022
> lo.latin1Decode(cversion(0))
BoringSSL
> fs.readdir_sync(`/proc/${lo.core.getpid()}/map_files`)
