{
  "targets": [
    {
      "target_name": "memfd",
      "sources": [ "memfd.cc" ],
      "cflags_cc": [ "-O3", "-march=native", "-mtune=native" ]
    },
    {
      "target_name": "linecount",
      "sources": [ "linecount.cc" ],
      "cflags_cc": [ "-O3", "-march=native", "-mtune=native" ]
    },
    {
      "target_name": "demo",
      "sources": [ "demo.cc" ]
    },
  ]
} 
