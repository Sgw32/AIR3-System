/*
 * Robotic Research Group (RRG)
 * State University of Piaui (UESPI), Brazil - Piauí - Teresina
 *
 * FuzzyIO.cpp
 *
 *      Author: Msc. Marvin Lemos <marvinlemos@gmail.com>
 *              AJ Alves <aj.alves@zerokol.com>
 *          Co authors: Douglas S. Kridi <douglaskridi@gmail.com>
 *                      Kannya Leal <kannyal@hotmail.com>
 */
#include "FuzzyIO.h"

// CONSTRUTORES
FUZZYLIB_DLL FuzzyIO::FuzzyIO(){
}

FUZZYLIB_DLL FuzzyIO::FuzzyIO(int index){
	this->index = index;
	// Iniciando os ponteiros como nulo
	this->fuzzySets			= NULL;
	this->fuzzySetsCursor	= NULL;
}

// DESTRUTOR
FUZZYLIB_DLL FuzzyIO::~FuzzyIO(){
	this->cleanFuzzySets(this->fuzzySets);
}

// MÉTODOS PÚBLICOS
FUZZYLIB_DLL int FuzzyIO::getIndex(){
	return this->index;
}

FUZZYLIB_DLL void FuzzyIO::setCrispInput(float crispInput){
	this->crispInput = crispInput;
}

FUZZYLIB_DLL float FuzzyIO::getCrispInput(){
	return this->crispInput;
}

FUZZYLIB_DLL bool FuzzyIO::addFuzzySet(FuzzySet* fuzzySet){
	fuzzySetArray *aux;
	// Alocando espaço na memória
	if((aux = (fuzzySetArray *) malloc(sizeof(fuzzySetArray))) == NULL){
		return false;
	}
	aux->fuzzySet 	= fuzzySet;
	aux->next 		= NULL;

	if(this->fuzzySets == NULL){
		this->fuzzySets = aux;
		this->fuzzySetsCursor	= aux;
	}else{
		this->fuzzySetsCursor->next = aux;
		this->fuzzySetsCursor = aux;
	}
	return true;
}

FUZZYLIB_DLL void FuzzyIO::resetFuzzySets(){
	fuzzySetArray* fuzzySetsAux;
    fuzzySetsAux = this->fuzzySets;
    // Calculando as pertinências de totos os FuzzyInputs
    while(fuzzySetsAux != NULL){
        fuzzySetsAux->fuzzySet->reset();
        fuzzySetsAux = fuzzySetsAux->next;
    }
}

// MÉTODOS PROTEGIDOS
FUZZYLIB_DLL void FuzzyIO::cleanFuzzySets(fuzzySetArray *aux){
	if(aux != NULL){
		// Esvaziando a memória alocada
		this->cleanFuzzySets(aux->next);
		free(aux);
	}
}