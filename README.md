# huffman-encoding
BBM203 Assignment - Jan 2021 - second year - fall semester
<br>
<br>
Huffman algorithm is a powerful algorithm that is used for compressing textual data to make file occupy
less space with respect to number of bytes. Intuitively, the algorithm works based on a frequency sorted
binary tree to encode the input.
Normally, textual data is stored using ASCII encoding with 8 bits per character. 8 bits fixed encoding is not
an efficient way to store large data, thus Huffman encoding uses binary encoding with variable sizes. The
advantage of this idea is that characters with high frequency is given short encoding while ones with low
frequency is given high encoding.
<br>
<br>
In this assignment, we have implemented a file compression algorithm based on Huffman coding with
trees.
<br>
1. program compresses given file using Huffman algorithm for encoding,
2. program decompresses given file using the same algorithm for decoding.
