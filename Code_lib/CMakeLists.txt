project(Code_lib)

set(HEADER_FILES
        Node.h
        PriorityQueue.h
        Huffman.h


)

set(SOURCE_FILES
        Node.cpp
        PriorityQueue.cpp
        Huffman.cpp
)

add_library(Code_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})