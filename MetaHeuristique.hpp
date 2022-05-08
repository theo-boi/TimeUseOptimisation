#include "Instance.hpp"
#include "Solution.hpp"
#include "Heuristique.hpp"
#include "Outils.hpp"

using namespace std;

#pragma once
class MetaHeuristique
{
public:


// ################### Algorithmes g�n�raux pour am�liorer la solution initiale ###################

	/// <summary>
	/// Calcule et renvoie une meilleure solution si elle est trouv�e que celle initiale, � partir d'une m�ta-heuristique � aproche trajectoire et de type Recherche � voisinage variable (RVV).
	/// Parcourt progressivement l'espace des solutions en s'extrayant � chaque changement d'op�rateur d'un optimal local qui n'est pas global.
	/// </summary>
	/// 
	/// <param name="solutionRealisable"></param>
	/// <param name="instance"></param>
	/// <param name="coeff_Valeur_FO_Contrainte"></param>
	/// <param name="chrono_start"></param>
	/// <returns>Une meilleure solution que celle initiale ou rien</returns>
	static Solution* Descente_Voisinage_Variable(Solution solutionInitiale, Instance* instance, float coeff_Valeur_FO_Contrainte, chrono::time_point<chrono::system_clock> chrono_start);


	/// <summary>
	/// Calcule et renvoie une meilleure solution si elle est trouv�e, en explorant le voisinage d'une solution r�alisable avec un op�rateur donn� et en retire l'optimal local si le temps le permet.
	/// </summary>
	/// 
	/// <param name="solutionRealisable"></param>
	/// <param name="instance"></param>
	/// <param name="k"></param>
	/// <param name="coeff_Valeur_FO_Contrainte"></param>
	/// <param name="chrono_start"></param>
	/// <returns>Une meilleure solution que celle du voisinage pr�c�dent ou rien</returns>
	static Solution* Recherche_Meilleure_Solution_Voisinage(Solution solutionRealisable, Instance* instance, int k, float coeff_Valeur_FO_Contrainte, chrono::time_point<chrono::system_clock> chrono_start);


// ################### Op�rations param�trables qui �x�cutent les op�rateurs pour explorer le voisinage d'une solution ###################

	/// <summary>
	/// Associe un candidat � une meilleure solution voisine si elle existe, en fonction de l'op�rateur de modification de shift choisi.
	/// Est param�tr�e lors de la recherche de meilleure solution du voisinage.
	/// </summary>
	/// 
	/// <param name="solutionRealisable"></param>
	/// <param name="candidat"></param>
	/// <param name="solutionVoisine"></param>
	/// <param name="instance"></param>
	/// <param name="coeff_Valeur_FO_Contrainte"></param>
	/// <param name="personne"></param>
	/// <param name="jour"></param>
	/// <param name="nombre_shift"></param>
	/// <param name="OperateurModificationShift"></param>
	static void Operation_Operateur_Modification_Shift(Solution* solutionRealisable, Solution** candidat, Solution* solutionVoisine, Instance* instance, float coeff_Valeur_FO_Contrainte,
		int personne, int jour, int nombre_shift,
		void OperateurModificationShift(Solution*, int, int, int));


	/// <summary>
	/// Associe un candidat � une meilleure solution voisine si elle existe, en fonction de l'op�rateur de swap choisi.
	/// Est param�tr�e lors de la recherche de meilleure solution du voisinage.
	/// </summary>
	/// 
	/// <param name="solutionRealisable"></param>
	/// <param name="candidat"></param>
	/// <param name="solutionVoisine"></param>
	/// <param name="instance"></param>
	/// <param name="coeff_Valeur_FO_Contrainte"></param>
	/// <param name="personne"></param>
	/// <param name="jour"></param>
	/// <param name="OperateurSwap"></param>
	/// <param name="modulo"></param>
	/// <param name="deplacement"></param>
	static void Operation_Operateur_Swap(Solution* solutionRealisable, Solution** candidat, Solution* solutionVoisine, Instance* instance, float coeff_Valeur_FO_Contrainte,
		int personne, int jour,
		void OperateurSwap(Solution*, int, int, int, int, int), int moduloX, int moduloY, int deplacement);


// ################### Op�rateurs qui cr�e un nouveau voisin d'une solution ###################
	
	/// <summary>
	/// Fait varier incr�mentalement un jour de travail en un autre jour de travail.
	/// </summary>
	/// 
	/// <param name="uneSolution"></param>
	/// <param name="nombre_shift"></param>
	/// <param name="personne"></param>
	/// <param name="jour"></param>
	static void Operateur_Modification_Shift_Incrementation(Solution* uneSolution, int nombre_shift, int personne, int jour);


	/// <summary>
	/// Fait varier les jours de fa�on relativement al�atoire.
	/// Donne une probabilit� d'environ 2/7 de changer d'�tat entre jour de travail et jour de repos, et associe un jour de travail al�atoire.
	/// </summary>
	/// 
	/// <param name="uneSolution"></param>
	/// <param name="nombre_shiftPlusUn"></param>
	/// <param name="personne"></param>
	/// <param name="jour"></param>
	static void Operateur_Modification_Shift_Aleatoire(Solution* uneSolution, int nombre_shiftPlusUn, int personne, int jour);


	/// <summary>
	/// Echange les shifts entre deux jours d'une personne donn�e.
	/// </summary>
	/// 
	/// <param name="uneSolution"></param>
	/// <param name="nombre_jour"></param>
	/// <param name="personne"></param>
	/// <param name="jour"></param>
	/// <param name="b"></param>
	static void Operateur_Swap_Jour(Solution* uneSolution, int nombre_personne, int nombre_jour, int personne, int jour, int deplacement);


	/// <summary>
	/// Echange les shifts entre deux personnes d'un jour donn�.
	/// </summary>
	/// 
	/// <param name="uneSolution"></param>
	/// <param name="nombre_personne"></param>
	/// <param name="personne"></param>
	/// <param name="jour"></param>
	/// <param name="deplacement"></param>
	static void Operateur_Swap_Personne(Solution* uneSolution, int nombre_personne, int nombre_jour, int personne, int jour, int deplacement);

	/// <summary>
	/// Echange les shifts entre deux personnes et deux jours.
	/// </summary>
	/// 
	/// <param name="uneSolution"></param>
	/// <param name="nombre_personne"></param>
	/// <param name="nombre_jour"></param>
	/// <param name="personne"></param>
	/// <param name="jour"></param>
	/// <param name="deplacement"></param>
	static void Operateur_Swap_Personne_Jour(Solution* uneSolution, int nombre_personne, int nombre_jour, int personne, int jour, int deplacement);

};
