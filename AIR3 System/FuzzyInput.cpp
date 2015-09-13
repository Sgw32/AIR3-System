/*
 * Robotic Research Group (RRG)
 * State University of Piaui (UESPI), Brazil - Piauí - Teresina
 *
 * FuzzyInput.cpp
 *
 *      Author: Msc. Marvin Lemos <marvinlemos@gmail.com>
 *              AJ Alves <aj.alves@zerokol.com>
 *          Co authors: Douglas S. Kridi <douglaskridi@gmail.com>
 *                      Kannya Leal <kannyal@hotmail.com>
 */
#include "FuzzyInput.h"

// CONSTRUTORES
FUZZYLIB_DLL FuzzyInput::FuzzyInput() : FuzzyIO(){
}

FUZZYLIB_DLL FuzzyInput::FuzzyInput(int index) : FuzzyIO(index){
}

// DESTRUTOR
FUZZYLIB_DLL FuzzyInput::~FuzzyInput(){
}

// MÉTODOS PÚBLICOS
FUZZYLIB_DLL bool FuzzyInput::calculateFuzzySetPertinences(){
	fuzzySetArray *aux;
	aux = this->fuzzySets;

	while(aux != NULL){
		if (aux->fuzzySet != NULL){
			aux->fuzzySet->calculatePertinence(this->crispInput);
		}
		aux = aux->next;
	}
	
	return true;
}