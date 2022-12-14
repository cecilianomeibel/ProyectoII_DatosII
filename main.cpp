
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
//Clase para configurar los colores de los cuadros del tablero.
class Board {
public:
    int size = 8;

    void Draw(sf::RenderWindow& window) {
        sf::RectangleShape tile;

        tile.setSize(sf::Vector2f(75.f,75.f));
        for (int i = 0;i < size;i++) {
            for (int j = 0;j < size;j++) {
                tile.setPosition(sf::Vector2f(75*i,75*j));
                if ((i + j) % 2 == 0) {
                    tile.setFillColor(sf::Color(231,179,133)); //Color beige
                }
                else {
                    tile.setFillColor(sf::Color(92,37,0)); //Color cafe
                }
                window.draw(tile);

                //Aca se crea la columna y fila para la numeracion
                //Rectangulo vertical
                sf::RectangleShape tile1;
                tile1.setSize(sf::Vector2f(100.f,600.f));
                tile1.setPosition(sf::Vector2f(600,0));
                tile1.setFillColor(sf::Color(139,69,19));
                window.draw(tile1);

                //Rectangulo horizontal

                sf::RectangleShape tile2;
                tile2.setSize(sf::Vector2f(600.f,100.f));
                tile2.setPosition(sf::Vector2f(0,600));
                tile2.setFillColor(sf::Color(139,69,19));
                window.draw(tile2);

                //Aca se van a numerar las columnas del tablero (A-H)
                sf:: Text textA, textB, textC, textD , textE, textF, textG, textH;
                sf:: Font font;
                font.loadFromFile("/home/gabrielwolf/Documents/WorkSpace Proyecto II/ProyectoII_DatosII/Garuda.ttf");
                //Seleccionar fuente
                textA.setFont(font); textB.setFont(font); textC.setFont(font); textD.setFont(font);
                textE.setFont(font); textF.setFont(font); textG.setFont(font); textH.setFont(font);
                //Seleccionar el string a mostrar
                textA.setString("A"); textB.setString("B"); textC.setString("C");textD.setString("D");
                textE.setString("E"); textF.setString("F"); textG.setString("G");textH.setString("H");
                //Seleccionar el tama??o
                textA.setCharacterSize(22); textB.setCharacterSize(22);textC.setCharacterSize(22);
                textD.setCharacterSize(22); textE.setCharacterSize(22); textF.setCharacterSize(22);
                textG.setCharacterSize(22); textH.setCharacterSize(22);
                //Seleccionar el color
                textA.setFillColor(sf::Color::Black); textB.setFillColor(sf::Color::Black); textC.setFillColor(sf::Color::Black);
                textD.setFillColor(sf::Color::Black); textE.setFillColor(sf::Color::Black);textF.setFillColor(sf::Color::Black);
                textG.setFillColor(sf::Color::Black); textH.setFillColor(sf::Color::Black);
                //Seleccionar posicion del texto
                textA.setPosition(sf::Vector2f(30,610)); textB.setPosition(sf::Vector2f(105,610));textC.setPosition(sf::Vector2f(180,610));
                textD.setPosition(sf::Vector2f(255,610)); textE.setPosition(sf::Vector2f(330,610)); textF.setPosition(sf::Vector2f(410,610));
                textG.setPosition(sf::Vector2f(480,610));textH.setPosition(sf::Vector2f(550,610));
                //Mostrar en pantalla
                window.draw(textA); window.draw(textB); window.draw(textC); window.draw(textD);
                window.draw(textE); window.draw(textF); window.draw(textG); window.draw(textH);

                //Aca se van a numerar las filas del tablero (1-8)
                sf:: Text text1, text2, text3, text4 , text5, text6, text7, text8;
                //Seleccionar fuente
                text1.setFont(font); text2.setFont(font); text3.setFont(font); text4.setFont(font);
                text5.setFont(font); text6.setFont(font); text7.setFont(font); text8.setFont(font);
                //Seleccionar el string a mostrar
                text1.setString("1"); text2.setString("2"); text3.setString("3");text4.setString("4");
                text5.setString("5"); text6.setString("6"); text7.setString("7");text8.setString("8");
                //Seleccionar el tama??o
                text1.setCharacterSize(22); text2.setCharacterSize(22);text3.setCharacterSize(22);
                text4.setCharacterSize(22); text5.setCharacterSize(22); text6.setCharacterSize(22);
                text7.setCharacterSize(22); text8.setCharacterSize(22);
                //Seleccionar el color
                text1.setFillColor(sf::Color::Black); text2.setFillColor(sf::Color::Black); text3.setFillColor(sf::Color::Black);
                text4.setFillColor(sf::Color::Black); text5.setFillColor(sf::Color::Black);text6.setFillColor(sf::Color::Black);
                text7.setFillColor(sf::Color::Black); text8.setFillColor(sf::Color::Black);
                //Seleccionar posicion del texto
                text1.setPosition(sf::Vector2f(620,550)); text2.setPosition(sf::Vector2f(620,470));text3.setPosition(sf::Vector2f(620,400));
                text4.setPosition(sf::Vector2f(620,325)); text5.setPosition(sf::Vector2f(620,245)); text6.setPosition(sf::Vector2f(620,175));
                text7.setPosition(sf::Vector2f(620,100));text8.setPosition(sf::Vector2f(620,25));
                //Mostrar en pantalla
                window.draw(text1); window.draw(text2); window.draw(text3); window.draw(text4);
                window.draw(text5); window.draw(text6); window.draw(text7); window.draw(text8);
            }
        }
    }

    void Highlight(sf::RenderWindow& window, int x, int y) {
        sf::RectangleShape tile;
        tile.setSize(sf::Vector2f(75.f, 75.f));
        tile.setFillColor(sf::Color::Green);
        tile.setPosition(sf::Vector2f(75 * x, 75 * y));
        window.draw(tile);
    }
};
//jj
class Piece {
public:
    float radius = 30;
    int x;
    int y;
    bool isAlive;
    bool isKing = false;
    sf::Color color;

    //Metodo Draw: Permite dibujar la pieza en el tablero, adem??s posee un caso si la pieza se convierte en rey o no
    void Draw(sf::RenderWindow& window) {
        if (isAlive) {
            sf::CircleShape shape(radius);
            shape.setFillColor(color);
            if (isKing) {
                shape.setOutlineThickness(3.f);
                shape.setOutlineColor(sf::Color::Yellow);
            }
            shape.setPosition(sf::Vector2f(x * 75 + (75 - radius * 2) / 2, y * 75 + (75 - 2 * radius) / 2));
            window.draw(shape);
        }
    }
};

void Setup(sf::RenderWindow& window, Piece* WhitePieces, Piece* BlackPieces) {
    int m = 0;
    for (int i = 0;i < 3;i++) {
        for (int j = (int)!(i%2 & 1);j < 8;j += 2) {
            BlackPieces[m].isAlive = true;
            BlackPieces[m].x = j;
            BlackPieces[m].y = i;
            m++;
        }
        
    }
    m = 0;
    for (int i = 0;i < 3;i++) {
        for (int j = (int)(i % 2 & 1);j < 8;j += 2) {
            WhitePieces[m].isAlive = true;
            WhitePieces[m].x = j;
            WhitePieces[m].y = 7-i;
            m++;
        }

    }
}

Piece* FindPiece(int x, int y, Piece* WhitePieces, Piece* BlackPieces) {
    for (int i = 0; i < 12;i++) {
        if (WhitePieces[i].x == x && WhitePieces[i].y == y) {
            if (WhitePieces[i].isAlive) {
                return &WhitePieces[i];
            }
        }
        if (BlackPieces[i].x == x && BlackPieces[i].y == y) {
            if (BlackPieces[i].isAlive) {
                return &BlackPieces[i];
            }
        }
    }
    return NULL;
}

void KillPiece(int x, int y, Piece* WhitePieces, Piece* BlackPieces, int *turn) {
    FindPiece(x, y, WhitePieces, BlackPieces)->isAlive = false;
    *turn = ((*turn == 1) ? 2 : 1);
    return;
}

int MovePiece(int x, int y, Piece* s_Piece, Piece* WhitePieces, Piece* BlackPieces, int *turn) {
        if (s_Piece->color == sf::Color::White || s_Piece->color == sf::Color::Black && s_Piece->isKing) {
            if (x == s_Piece->x - 1 && y == s_Piece->y - 1) {
                if (!FindPiece(x, y, WhitePieces, BlackPieces)) {
                    *turn = ((*turn == 1) ? 2 : 1);
                    s_Piece->x = x;
                    s_Piece->y = y;
                    return 1;
                }
            }
            if (x == s_Piece->x + 1 && y == s_Piece->y - 1) {
                if (!FindPiece(x, y, WhitePieces, BlackPieces)) {
                    *turn = ((*turn == 1) ? 2 : 1);
                    s_Piece->x = x;
                    s_Piece->y = y;
                    return 1;
                }
            }
            if (x == s_Piece->x - 2 && y == s_Piece->y - 2) {
                if (!FindPiece(x, y, WhitePieces, BlackPieces) && FindPiece(x+1,y+1,WhitePieces, BlackPieces) != NULL && FindPiece(x + 1, y + 1, WhitePieces, BlackPieces)->color != s_Piece->color) {
                    *turn = ((*turn == 1) ? 2 : 1);
                    KillPiece(x + 1, y + 1, WhitePieces, BlackPieces, turn);
                    s_Piece->x = x;
                    s_Piece->y = y;
                    return 1;
                }
            }
            if (x == s_Piece->x + 2 && y == s_Piece->y - 2) {
                if (!FindPiece(x, y, WhitePieces, BlackPieces) && FindPiece(x - 1, y + 1, WhitePieces, BlackPieces) != NULL && FindPiece(x - 1, y + 1, WhitePieces, BlackPieces)->color != s_Piece->color) {
                    *turn = ((*turn == 1) ? 2 : 1);
                    KillPiece(x - 1, y + 1, WhitePieces, BlackPieces, turn);
                    s_Piece->x = x;
                    s_Piece->y = y;
                    return 1;
                }
            }
        }
        if (s_Piece->color == sf::Color::Black || s_Piece->color == sf::Color::White && s_Piece->isKing) {
            if (x == s_Piece->x - 1 && y == s_Piece->y + 1) {
                if (!FindPiece(x, y, WhitePieces, BlackPieces)) {
                    *turn = ((*turn == 1) ? 2 : 1);
                    s_Piece->x = x;
                    s_Piece->y = y;
                    return 1;
                }
            }
            if (x == s_Piece->x + 1 && y == s_Piece->y + 1) {
                if (!FindPiece(x, y, WhitePieces, BlackPieces)) {
                    *turn = ((*turn == 1) ? 2 : 1);
                    s_Piece->x = x;
                    s_Piece->y = y;
                    return 1;
                }
            }
            if (x == s_Piece->x - 2 && y == s_Piece->y + 2) {
                if (!FindPiece(x, y, WhitePieces, BlackPieces) && FindPiece(x + 1, y - 1, WhitePieces, BlackPieces) != NULL && FindPiece(x + 1, y - 1, WhitePieces, BlackPieces)->color != s_Piece->color) {
                    *turn = ((*turn == 1) ? 2 : 1);
                    s_Piece->x = x;
                    s_Piece->y = y;
                    KillPiece(x + 1, y - 1, WhitePieces, BlackPieces, turn);
                    return 1;
                }
            }
            if (x == s_Piece->x + 2 && y == s_Piece->y + 2) {
                if (!FindPiece(x, y, WhitePieces, BlackPieces) && FindPiece(x - 1, y - 1, WhitePieces, BlackPieces) != NULL && FindPiece(x - 1, y - 1, WhitePieces, BlackPieces)->color != s_Piece->color) {
                    *turn = ((*turn == 1) ? 2 : 1);
                    s_Piece->x = x;
                    s_Piece->y = y;
                    KillPiece(x - 1, y - 1, WhitePieces, BlackPieces, turn);
                    return 1;
                }
            }
        }
        return 0;
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16.0;
    sf::RenderWindow window(sf::VideoMode(650, 650), "Inmersive Checkers", sf::Style::Default, settings); //Se crea la ventana,se establecen sus dimensiones y nombre
    sf::Event event;
    Board board;
    int grid[8][8];
    Piece WhitePieces[12];
    Piece BlackPieces[12];
    bool selected = false;
    Piece* SelectedPiece = NULL;
    int turn = 1;

    for (int i = 0;i < 12;i++) {
        BlackPieces[i].color = sf::Color::Black;
        WhitePieces[i].color = sf::Color::White;
    }

    
    Setup(window, WhitePieces, BlackPieces);

    while (window.isOpen()) {   //la ventana se abre constantemente
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();   //Comprueba si la ventana se esta cerrando o no
            }
            
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    selected = !selected;
                }
            }
        }

        window.clear();  //Se limpian los cambios anteriores
        //Aca dentro se coloca lo que se quiere dibujar
        board.Draw(window);  //se dibuja la ventana

        if (SelectedPiece != NULL) {
            board.Highlight(window, SelectedPiece->x, SelectedPiece->y);
        }
        
        for (int i = 0;i < 12;i++) {
            BlackPieces[i].Draw(window);
            WhitePieces[i].Draw(window);
        }

        if (selected) {
            int x = sf::Mouse::getPosition(window).x / 75;
            int y = sf::Mouse::getPosition(window).y / 75;
            if (FindPiece(x, y, WhitePieces, BlackPieces) && (FindPiece(x, y, WhitePieces, BlackPieces)->color == sf::Color::White && turn == 1 || FindPiece(x, y, WhitePieces, BlackPieces)->color == sf::Color::Black && turn == 2)) {
                if (FindPiece(x, y, WhitePieces, BlackPieces) == SelectedPiece) {
                    SelectedPiece = NULL;
                }
                else {
                    SelectedPiece = FindPiece(x, y, WhitePieces, BlackPieces);
                }
            
                selected = false;
            }
            else if (SelectedPiece != NULL && MovePiece(x, y, SelectedPiece, WhitePieces, BlackPieces, &turn)) {
                selected = false;
                SelectedPiece = NULL;
            }
            selected = false;
        }
        for (int i = 0;i < 12;i++) {
            if (WhitePieces[i].y == 0) {
                WhitePieces[i].isKing = true;
            }
            if (BlackPieces[i].y == 7) {
                BlackPieces[i].isKing = true;
            }
        }
        

        window.display();
    }
    return 0;
}

//Prueba
