{
  "targets": [
    {
      "target_name": "linecount",
      "sources": [
        "src/linecount.cc"
      ],
      "cflags_cc": [
        "-O3",
        "-march=native",
        "-mtune=native"
      ]
    },
    {
      "target_name": "demo",
      "sources": [
        "src/demo.cc"
      ],
      "cflags_cc": [
        "-O3",
        "-march=native",
        "-mtune=native"
      ]
    },
    {
      "target_name": "count",
      "sources": [
        "src/count.cc"
      ],
      "cflags_cc": [
        "-O3",
        "-march=native",
        "-mtune=native"
      ]
    },
    {
      "target_name": "ffast",
      "sources": [
        "src/ffast.cc"
      ],
      "cflags_cc": [
        "-O3",
        "-march=native",
        "-mtune=native"
      ]
    },
    {
      "target_name": "tcc",
      "sources": [
        "src/tcc.cc"
      ],
      "cflags_cc": [
        "-O3",
        "-march=native",
        "-mtune=native"
      ],
      "include_dirs": [
        "../lo/lib/tcc/deps/libtcc"
      ],
      "libraries": [
        "/media/andrew/OCZ/source2023/just-js/lo/lib/tcc/deps/libtcc/libtcc.a"
      ]
    },
    {
      "target_name": "noop",
      "sources": [
        "src/noop.cc"
      ],
      "cflags_cc": [
        "-O3",
        "-march=native",
        "-mtune=native"
      ]
    },
    {
      "target_name": "libssl",
      "sources": [
        "src/libssl.cc"
      ],
      "cflags_cc": [
        "-O3",
        "-march=native",
        "-mtune=native"
      ]
    }
  ]
}