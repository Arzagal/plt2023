cmake_minimum_required(VERSION 3.10)

project(ShadowHunter)

set(CMAKE_CXX_STANDARD 17)

# Recherche de la bibliothèque SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Ajout de l'exécutable en spécifiant tous les fichiers source
add_executable(MyGame main.cpp Player.cpp Darknlight.cpp DeckDark.cpp DeckLight.cpp DeckVision.cpp Card.cpp Board.cpp Game.cpp Vision.cpp Character.cpp Teams.cpp Dark.cpp)
