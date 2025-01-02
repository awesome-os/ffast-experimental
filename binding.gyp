{
  "targets": [
    {
      "target_name": "ffast",
      "sources": [
        "ffast.cc"
      ],
      "cflags_cc": [
        "-O3",
        "-march=native",
        "-mtune=native"
      ]
    },
    {
      "target_name": "noop",
      "sources": [
        "noop.cc"
      ],
      "cflags_cc": [
        "-O3",
        "-march=native",
        "-mtune=native"
      ]
    },
    {
      "target_name": "tcc",
      "include_dirs": [
        "../lo/lib/tcc/deps/libtcc"
      ],
      "libraries": [
        "/media/andrew/OCZ/source2023/just-js/lo/lib/tcc/deps/libtcc/libtcc.a"
      ],
      "sources": [
        "tcc.cc"
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
        "count.cc"
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
        "demo.cc"
      ]
    },
    {
      "target_name": "linecount",
      "sources": [
        "linecount.cc"
      ],
      "cflags_cc": [
        "-O3",
        "-march=native",
        "-mtune=native"
      ]
    }
  ]
}