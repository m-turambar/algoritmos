/* Imprimir todas las permutaciones en orden lexicografico
https://www.geeksforgeeks.org/lexicographic-permutations-of-string/
Ejemplo:
ABC:
ABC	ACB BAC BCA CAB CBA

*/
/*
Escribir un programa que imprima todas las permutaciones de una string dada-
Una permutación, es un rearreglo de los elementos de una lista ordenada S
en una con correspondencia 1 a 1 con S. Una cada de longitud n tiene n!
permutaciones.

Una de las soluciones usa backtracking:
Árbol de recursión para las permutaciones de "ABC":
https://media.geeksforgeeks.org/wp-content/cdn-uploads/NewPermutation.gif

Hace swaps, a veces de un caracter consigo mismo para conseguir generalidad.

*/
#include <iostream>

using namespace std;

/*Esto es una vil copia*/
/*Función para imprimir permutaciones de una string*/
void permutar(string s, int l, int r)
{
	// caso base
	if(l == r)
		cout << s << endl;
	else
	{
		for(int i=l; i<=r; ++i)
		{
			swap(s[l], s[i]);
			
			permutar(s, l+1, r);
			
			//a esto le llama backtrack
			swap(s[l], s[i]);
		}
	}
}

int main()
{
	string s = "ABC";
	int n = s.size();
	permutar(s, 0, n-1);
	return 0;
}