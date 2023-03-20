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

<br>

commands to run the program in the dev machine:

dos2unix *.txt
g++ -std=c++1y *.cpp -o Main (to create exe: g++ -std=c++1y *.cpp -o Main.exe)

encoding: 
./Main -i input_1.txt -encode (or ./Main.exe -i input_1.txt -encode)

decoding the encoded string: 
./Main -i decode_input_1.txt -decode (or ./Main.exe -i decode_input_1.txt -decode)

huffman coding of a particular character:
./Main -s character (or ./Main.exe -s character)

listing the tree:
./Main -l (or ./Main.exe -l)
