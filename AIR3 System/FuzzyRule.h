/*
 * Robotic Research Group (RRG)
 * State University of Piaui (UESPI), Brazil - Piauí - Teresina
 *
 * FuzzyRule.h
 *
 *      Author: Msc. Marvin Lemos <marvinlemos@gmail.com>
 *              AJ Alves <aj.alves@zerokol.com>
 *          Co authors: Douglas S. Kridi <douglaskridi@gmail.com>
 *                      Kannya Leal <kannyal@hotmail.com>
 */
#ifndef FUZZYRULE_H
#define FUZZYRULE_H

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
#include "FuzzyRuleAntecedent.h"
#include "FuzzyRuleConsequent.h"

class FUZZYLIB_DLL FuzzyRule {
	public:
		// CONSTRUTORES
		FuzzyRule();
		FuzzyRule(int index, FuzzyRuleAntecedent* fuzzyRuleAntecedent, FuzzyRuleConsequent* fuzzyRuleConsequent);
		// MÉTODOS PÚBLICOS
		int getIndex();
		bool evaluateExpression();
		bool isFired();

	private:
		// VARIÁVEIS PRIVADAS
		int index;
		bool fired;
		FuzzyRuleAntecedent* fuzzyRuleAntecedent;
		FuzzyRuleConsequent* fuzzyRuleConsequent;
};
#endif