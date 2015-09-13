/*
 * Robotic Research Group (RRG)
 * State University of Piaui (UESPI), Brazil - Piauí - Teresina
 *
 * FuzzyInput.h
 *
 *      Author: Msc. Marvin Lemos <marvinlemos@gmail.com>
 *              AJ Alves <aj.alves@zerokol.com>
 *          Co authors: Douglas S. Kridi <douglaskridi@gmail.com>
 *                      Kannya Leal <kannyal@hotmail.com>
 */
#ifndef FUZZYINPUT_H
#define FUZZYINPUT_H

#ifdef RUN3
#ifndef FUZZYLIB_DLL
#define FUZZYLIB_DLL __declspec( dllimport )
#endif
#endif

#ifndef FUZZYLIB_DLL
#ifndef FUZZYLIB_DLL
#define FUZZYLIB_DLL __declspec( dllexport )
#endif
#endif

// IMPORTANDO AS BIBLIOTECAS NECESSÁRIAS
#include "FuzzyIO.h"

class FUZZYLIB_DLL FuzzyInput : public FuzzyIO {
	public:
		// CONSTRUTORES
        FuzzyInput();
		FuzzyInput(int index);
		// DESTRUTOR
		~FuzzyInput();
		// MÉTODOS PÚBLICOS
		bool calculateFuzzySetPertinences();
};
#endif