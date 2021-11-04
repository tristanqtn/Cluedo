/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_PARTIE_H_INCLUDED
#define HEADER_PARTIE_H_INCLUDED
/*********************************************************************************************************/


/**< LIBRARIES >******************************************************************************************/
#include "header_case.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_meurtrier.h"
/*********************************************************************************************************/


/**< CLASSE >*********************************************************************************************/
class Partie
{
    private :

        ///varialbles priv�es
        int m_nb_IA;
        int m_nb_joueur;

        Meurtrier m_meurtrier;

        std::vector <Joueur> m_joueurs;
        std::vector <Carte_alibi> m_deck_cartes;

        ///fonctions priv�es, seulement utile au sein de la classe
        std::vector <Carte_alibi> creer_deck_lieux();
        std::vector <Carte_alibi> creer_deck_armes();
        std::vector <Carte_alibi> creer_deck_personnage();

        bool doublon_pseudo(std::string chaine); //verification de la presence de doublons de pseudo

        Meurtrier creer_meurtrier(std::vector <Carte_alibi>& deck_personnages, std::vector <Carte_alibi>& deck_lieux, std::vector <Carte_alibi>& deck_armes); //lfonction de cr�ation d'un meurtrier

        //tour d'une IA
        void tour_IA(int i);

        //tour d'un joueur
        bool tour_joueur(int i);

        //m�thodes d'accusation ou d'hypoth�ses
        void hypothese_finale(int i);
        bool accusation_finale(int i);



    public :

        ///constructeurs
        Partie(); //defaut
        Partie(Meurtrier _meurtrier, std::vector <Carte_alibi> _deck_cartes, std::vector <Joueur> _joueurs); //surcharg�

        ///destructeur
        ~Partie();

        ///methodes
        //getters
        int get_nb_IA() const;
        int get_nb_joueurs() const;
        int get_nb_tot_joueur() const;

        std::vector <Joueur> get_joueurs() const;
        std::vector <Carte_alibi> get_pioche() const;

        Meurtrier get_meurtrier() const;
        Carte_alibi get_carte(int valeur) const;

        Partie * get_pointeur();

        //setters
        void set_nb_IA(int valeur);
        void set_nb_joueur (int valeur);
        void set_meurtrier (Meurtrier tueur);
        void set_deck (std::vector <Carte_alibi> deck);

        //affichage
        void afficher_deck() const; //seulement utile pour verification de la bonne cr�ation des cartes, ne pas utiliser dans le jeu
        void afficher_meurtrier() const; //affichage des cartes alibis composants le meurtre

        //fonctionnement de la partie
        void creer_partie(); //cr�ation de la pioche + plateau
        void parametrer(); //recuperation des parametres (nb joueurs, nb IA, ...)
        void creer_joueurs(); //cr�ation des objets joueurs
        void creer_IA(); //cr�ation des objets IA
        void distribuer(); //distribution des cartes
        void lancer_partie (); //boucle de jeu



};
/*********************************************************************************************************/


#endif // HEADER_PARTIE_H_INCLUDED
