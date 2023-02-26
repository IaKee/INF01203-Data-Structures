# Final Project Description - Word Frequency Counter

This project is a word frequency counter for a given text. The goal is to count the frequency of each word that appears in the text and output the results in alphabetical order. This project was developed as a final project for the Data Structures course.

## Authors
- Giordano Souza de Paula (00308054)
- Sabryna Trindade (00302133)


## Libraries Used

The following libraries were used in this project:

- stdio.h
- ctype.h
- string.h
- time.h
- windows.h
- pthread.h
- "trab.h" (a user-defined header file)

### Constants Defined

The following constants were defined in this project:

- TAM_MAX_CAMINHO: 250 (maximum size of the file path)
Structs Used

The following structs were used in this project:

- avlNode: a struct representing a node in an AVL tree used for word frequency counting
- RBNode: a struct representing a node in a red-black tree used for word frequency counting

### Functions Used

The following functions were used in this project:

- imprime_apresentacao(): a function that prints the project introduction and author information
- solicita_arquivos(): a function that prompts the user for the file paths of the text and operations files, and opens the files
- coloca_formato(): a function that adds the ".txt" extension to a file path if it doesn't already have it
- abre_arquivo(): a function that opens the text and operations files and returns an error code if it can't open them
- trata_linha(): a function that processes a line of text and updates the word frequency counters in the AVL and red-black trees
- imprime_saida(): a function that outputs the word frequency counters in alphabetical order
- imprime_estatisticas(): a function that outputs the execution time of the program and other statistics

### Conclusion

This project demonstrates the use of AVL and red-black trees for word frequency counting. By using these data structures, the program is able to efficiently count the frequency of each word in the text and output the results in alphabetical order.