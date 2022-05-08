#include <iostream>
#include <chrono>
#include <deque>
#include "Instance.hpp"
#include "Solution.hpp"

using namespace std;

#pragma once
class Outils
{
public:

	/// <summary>
	/// Calcule et renvoie le temps �coul� en secondes depuis que le chronom�tre pass� en argument a �t� lanc�.
	/// </summary>
	/// 
	/// <param name="chrono_start"></param>
	/// <returns>Le temps �coul� en secondes</returns>
	static int get_Secondes_Ecoulees(chrono::time_point<chrono::system_clock> chrono_start);

	/// <summary>
	/// Alloue, initialise et renvoie une solution en recopiant celle pass�e en param�tre et sa valeur de fonction objective.
	/// </summary>
	/// 
	/// <param name="uneSolution"></param>
	/// <returns>Une copie de uneSolution</returns>
	static Solution* Copie_Solution(Solution* uneSolution);

	/// <summary>
	/// Affiche la solution pass�e en param�tre dans la console avec les personnes en lignes et les jours en colonne.
	/// </summary>
	/// 
	/// <param name="uneSolution"></param>
	static void print_Solution(Solution* uneSolution);

	/// <summary>
	/// Calcule et renvoie la valeur de la fonction objective de la solution, en utilisant les donn�es de l'instance.
	/// </summary>
	/// 
	/// <param name="uneSolution"></param>
	/// <param name="instance"></param>
	/// <returns>La valeur de la fonction objective</returns>
	static int Calcul_Valeur_FO(Solution* uneSolution, Instance* instance);

	/// <summary>
	/// Calcule et renvoie la p�nalisation � ajouter � la valeur de la fonction objective de la solution, en utilisant les donn�es de l'instance.
	/// Applique entre autre le coefficient multiplicateur de la valeur initiale pass� en param�tre en cas de contrainte non respect�e.
	/// </summary>
	/// 
	/// <param name="uneSolution"></param>
	/// <param name="instance"></param>
	/// <param name="coeff_Valeur_FO_Contrainte"></param>
	/// <returns>La p�nalisation de la valeur de la fonction objective</returns>
	static int Calcul_Penalisation_Valeur_FO(Solution* uneSolution, Instance* instance, float coeff_Valeur_FO_Contrainte);

	/// <summary>
	/// Calcule et renvoie la liste des personnes dans la solution dont une ou plusieurs contraintes ne sont pas respect�es, en utilisant les donn�es de l'instance.
	/// </summary>
	/// 
	/// <param name="uneSolution"></param>
	/// <param name="instance"></param>
	/// <returns></returns>
	static deque<int> Personnes_Contraintes_Non_Respectes(Solution* uneSolution, Instance* instance);

	/// <summary>
	/// Indique si la valeur (en opposition � sa cl�) d'une paire a et plus petite que celle d'une paire b.
	/// </summary>
	/// 
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	static bool Comparer(pair<int, int>& a, pair<int, int>& b);

	/// <summary>
	/// Applique et renvoie le r�sultat du codage lin�aire, R -> R, x -> f(x), avec f : f(x) = (ax + b) % modulo.
	/// </summary>
	/// 
	/// <param name="a"></param>
	/// <param name="x"></param>
	/// <param name="b"></param>
	/// <param name="modulo"></param>
	/// <returns></returns>
	static int Codage_Lineaire(double a, int x, int b, int modulo);
	
};

