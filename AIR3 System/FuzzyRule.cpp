/*
 * Robotic Research Group (RRG)
 * State University of Piaui (UESPI), Brazil - Piauí - Teresina
 *
 * FuzzyOutput.cpp
 *
 *      Author: Msc. Marvin Lemos <marvinlemos@gmail.com>
 *              AJ Alves <aj.alves@zerokol.com>
 *          Co authors: Douglas S. Kridi <douglaskridi@gmail.com>
 *                      Kannya Leal <kannyal@hotmail.com>
 */
#include "FuzzyRule.h"

FUZZYLIB_DLL FuzzyRule::FuzzyRule(){
}

FUZZYLIB_DLL FuzzyRule::FuzzyRule(int index, FuzzyRuleAntecedent* fuzzyRuleAntecedent, FuzzyRuleConsequent* fuzzyRuleConsequent){
	this->index = index;
	this->fuzzyRuleAntecedent = fuzzyRuleAntecedent;
	this->fuzzyRuleConsequent = fuzzyRuleConsequent;
	this->fired = false;
}

FUZZYLIB_DLL int FuzzyRule::getIndex(){
	return this->index;
}

FUZZYLIB_DLL bool FuzzyRule::evaluateExpression(){
	if (this->fuzzyRuleAntecedent != NULL){
		float powerOfAntecedent = this->fuzzyRuleAntecedent->evaluate();

		(powerOfAntecedent > 0.0) ?	(this->fired = true) : (this->fired = false);
		
		this->fuzzyRuleConsequent->evaluate(powerOfAntecedent);
	}
	return this->fired;
}

FUZZYLIB_DLL bool FuzzyRule::isFired(){
	return this->fired;
}