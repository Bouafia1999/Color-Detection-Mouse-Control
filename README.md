# Color-Detection-Mouse-Control
# Détection de Couleurs et Contrôle de la Souris

Ce projet utilise OpenCV pour détecter des objets de différentes couleurs à partir de la vidéo capturée par une caméra et simuler des clics de souris en fonction des objets détectés. La détection est réalisée pour les couleurs rouge, bleu et vert.

## Fonctionnalités

- **Détection des Couleurs** : Identifie les objets rouges, bleus et verts dans le flux vidéo.
- **Contrôle de la Souris** : 
  - Déplace le curseur de la souris à la position d'un objet rouge détecté.
  - Simule un clic droit lorsque un objet bleu est détecté.
  - Simule un clic gauche lorsque un objet vert est détecté.
- **Affichage en Temps Réel** : Affiche le flux vidéo avec les détections en cours.

## Prérequis

- **OpenCV** : Assurez-vous que OpenCV est installé et correctement configuré dans votre environnement de développement.
- **Environnement Windows** : Ce projet utilise la fonction `SendInput` de Windows pour simuler les clics de souris.

## Installation

1. **Clonez le Dépôt**

   git clone https://github.com/Bouafia1999/Color-Detection-Mouse-Control.git
