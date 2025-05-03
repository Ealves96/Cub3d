<!---banner--->
<h1 align="center">
 🎮 Cub3D
</h1>

<p align="center">
    <img src="https://res.cloudinary.com/dzo1cimyr/image/upload/v1746300692/cub3d_dn7sub.gif" width="800">
</p>

## 📝 Description
Cub3D est un projet graphique inspiré du célèbre jeu Wolfenstein 3D. Ce projet utilise la technique du raycasting pour créer une représentation 3D à partir d'une carte 2D, permettant au joueur de se déplacer dans un environnement en trois dimensions.

## 🚀 Fonctionnalités
- 🎯 Raycasting pour le rendu 3D
- 🗺️ Parsing de cartes personnalisées
- 🎨 Textures pour les murs
- 🎮 Contrôles de mouvement fluides
- 🔄 Rotation de la caméra
- 🎯 Détection des collisions

## 🛠️ Installation
```bash
# Cloner le repository
git clone [URL_DU_REPO]

# Se déplacer dans le dossier du projet
cd Cub3D

# Compiler le projet
make
```

## 🎮 Utilisation
```bash
# Lancer le jeu
./cub3D [chemin_vers_la_carte]
```

### Contrôles
- `W` : Avancer
- `S` : Reculer
- `A` : Se déplacer à gauche
- `D` : Se déplacer à droite
- `←` : Tourner à gauche
- `→` : Tourner à droite
- `ESC` : Quitter le jeu

## 📋 Format de la carte
La carte doit être au format `.cub` et doit contenir :
- Les textures des murs (NO, SO, EA, WE)
- Les couleurs du sol et du plafond
- La carte du niveau avec les caractères suivants :
  - `0` : Espace vide
  - `1` : Mur
  - `N/S/E/W` : Position de départ du joueur

## 🧪 Tests
Le projet inclut plusieurs cartes de test dans le dossier `maps/` pour vérifier le bon fonctionnement du jeu.

## 🛠️ Technologies et Langages
<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/> <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="Linux"/> <img src="https://img.shields.io/badge/Make-000000?style=for-the-badge&logo=make&logoColor=white" alt="Make"/> <img src="https://img.shields.io/badge/MLX-000000?style=for-the-badge&logo=minilibx&logoColor=white" alt="MLX"/>
</p>
