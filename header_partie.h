/**< PREPROCESSOR >***************************************************************************************/
#ifndef HEADER_PARTIE_H_INCLUDED
#define HEADER_PARTIE_H_INCLUDED
/*********************************************************************************************************/


/**< LIBRARIES >******************************************************************************************/
#include "header_case.h"
#include "header_carte.h"
#include "header_joueur.h"
#include "header_plateau.h"
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
        std::vector <IA> m_IA;
        std::vector <Carte_alibi> m_deck_cartes;

        Plateau m_board;

        int m_tour;

        ///fonctions priv�es, seulement utile au sein de la classe
        std::vector <Carte_alibi> creer_deck_lieux();
        std::vector <Carte_alibi> creer_deck_armes();
        std::vector <Carte_alibi> creer_deck_personnage();

        bool doublon_pseudo(std::string chaine); //verification de la presence de doublons de pseudo

        Meurtrier creer_meurtrier(std::vector <Carte_alibi>& deck_personnages, std::vector <Carte_alibi>& deck_lieux, std::vector <Carte_alibi>& deck_armes); //lfonction de cr�ation d'un meurtrier

        //tour d'une IA
        void tour_IA(int i);

        //tour d'un joueur
        bool tour_joueur(int i, bool & exit);

        //m�thodes d'accusation ou d'hypoth�ses
        void hypothese_finale(int i, std::string nom_station);
        bool accusation_finale(int i);

        void sauvegarder_joueurs();
        void recuperation_joueur();
        void recuperation_joueurs();
        Joueur recuperation();

        void sauvegarde_meurtrier();
        void recuperation_meurtrier();

        void recup_config();
        void sauvegarde_config();

        bool doublon_pion(std::string chaine);
        bool couleur_pion(std::string chaine);

        void afficher_type(Participant& a);
        bool pause();

        //affichage
        void afficher_deck() const; //seulement utile pour verification de la bonne cr�ation des cartes, ne pas utiliser dans le jeu
        void afficher_meurtrier() const; //affichage des cartes alibis composants le meurtre


    public :

        ///constructeurs
        Partie(); //defaut
        Partie(Meurtrier _meurtrier, std::vector <Carte_alibi> _deck_cartes, std::vector <Joueur> _joueurs, std::vector <IA> _IA, Plateau _board, int _tour); //surcharg�

        ///destructeur
        ~Partie();

        ///methodes
        //getters
        int get_nb_IA() const;
        int get_nb_joueurs() const;
        int get_nb_tot_joueur() const;
        int get_nb_tour() const;

        std::vector <IA> get_IA() const;
        std::vector <Joueur> get_joueurs() const;

        std::vector <Carte_alibi> get_pioche() const;

        Meurtrier get_meurtrier() const;
        Carte_alibi get_carte(int valeur) const;

        Partie * get_pointeur();

        void actualiser_allegro(int i);

        //setters
        void set_nb_IA(int valeur);
        void set_nb_joueur (int valeur);
        void set_meurtrier (Meurtrier tueur);
        void set_nb_tour(int valeur);
        void set_deck (std::vector <Carte_alibi> deck);

        //fonctionnement de la partie
        void creer_partie(); //cr�ation de la pioche + plateau
        void parametrer(); //recuperation des parametres (nb joueurs, nb IA, ...)
        void creer_joueurs(); //cr�ation des objets joueurs
        void creer_IA(); //cr�ation des objets IA
        void choix_pion(); //choix des pions
        void distribuer(); //distribution des cartes
        void initialisation(); //setup des elements de jeu
        void lancer_partie (); //boucle de jeu

        void sauvegarde_partie();
        void recuperation_tot_partie();

        int nombre_victoire();
        void incrementation_victoire();
        void historique_victoire(int nb_sauv);
        void sauvegarde_victoire(std::string pseudo, std::string personnage, std::string lieu, std::string arme, int tour);
};
/*********************************************************************************************************/


#endif // HEADER_PARTIE_H_INCLUDED
