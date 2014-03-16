algorithms
==========

A collection of Algorithms implemented to help study for CS 520

Everything works using STDIN and STDOUT.  File handling is tedious and I'd much rather pipe and redirect.

Example Usage:  
$ cd sorting  
$ make  
$ echo "3 5 1 2 4 9 7 9 3" | ./bubblesort  
$ cat data/002.A-100.txt | ./selection_sort > 100-sorted.txt  
$ cat data/003.A-200.txt | ./insertion_sort  

$ cd graphs  
$ make bfs  
$ cat non_weighted_data.txt | ./bfs  

