/// SIMILARITY DOCUMENTATION ///

Description :
this code uses cosine distance methode to measure similarity between two text files 
it first transfers files into strings using a buffer to store them in , calculates frequency of each word of the strings
and stores these frequencies into vectors to finally apply the cosine function and obtain similarity 

these steps are sequenced into functions to better model the code 


how to run :

in commande line , type :
+gcc -o similarity similarity.cpp <filename1.txt> <filename2.txt> 

file names are read from the commande line so making sure they are written correctly is important .
