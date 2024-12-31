{
  "targets": [
    {
      "target_name": "ffast",
      "sources": [ "ffast.cc" ],
      "cflags_cc": [ "-O3", "-march=native", "-mtune=native" ]
    },
    {
      "target_name": "linecount",
      "sources": [ "linecount.cc" ],
      "cflags_cc": [ "-O3", "-march=native", "-mtune=native" ]
    },
    {
      "target_name": "count",
      "sources": [ "count.cc" ],
      "cflags_cc": [ "-O3", "-march=native", "-mtune=native" ],
    },
    {
      "target_name": "demo",
      "sources": [ "demo.cc" ]
    },
  ]
} 
