#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "MainMenu.h"
#include "Ship.h"
#include "Enemy.h"
#include "Laser.h"
#include "Bomb.h"
#include "How2Play.h"
#include "SelectShip.h"
#include "Options.h"
#include "EnemyLaser.h"
#include "GameOver.h"
#include "Victory.h"
#include "Boss.h"
#include "BossLaser.h"
#include <vector>
#include <typeinfo>

using namespace sf;
using namespace std;

int main()
{
    // ustawianie okienka i jego limitu
    RenderWindow window{ VideoMode{800,600}, "Dzurek" };
    RectangleShape backgroundGame;
    Texture tloGame;
    tloGame.loadFromFile("tłociemniejsze.png");
    backgroundGame.setSize(Vector2f(800, 600));
    backgroundGame.setTexture(&tloGame);
    window.setFramerateLimit(144);
    MainMenu menu(800, 600);
    How2Play howplay(800, 600);
    SelectShip selectionofship(800, 600);
    Options optionsmenu(800, 600);
    GameOver loser(800, 600);
    Victory winer_winner_chicken_dinner(800, 600);
    int wyj = 0;
    int shipchoosen = 0;

    Font font;
    if (!font.loadFromFile("prawiearial.ttf"))
    {
        cout << "Nie laduje sie czcionka" << endl;
    }

    Text display[2];
    Text displayBossHP[1];

    display[0].setFillColor(Color::Cyan);
    display[0].setFont(font);
    display[0].setPosition(50, 10);
    display[0].setCharacterSize(30);

    display[1].setFillColor(Color::Cyan);
    display[1].setFont(font);
    display[1].setPosition(600, 10);
    display[1].setCharacterSize(30);

    displayBossHP[0].setFillColor(Color::Red);
    displayBossHP[0].setFont(font);
    displayBossHP[0].setPosition(320, 10);
    displayBossHP[0].setCharacterSize(30);

    // soundtrack
    Music soundtrack;
    SoundBuffer beep;
    SoundBuffer laser;
    SoundBuffer bomb;
    if (!soundtrack.openFromFile("soundtrack.ogg"))
    {
        return -1;
    }
    if (!beep.loadFromFile("bing.ogg")) {
        return -1;
    }
    if (!laser.loadFromFile("laser_shoot.ogg")) {
        return -1;
    }
    if (!bomb.loadFromFile("bomb.ogg")) {
        return -1;
    }
    soundtrack.setLoop(true);
    soundtrack.play();
    soundtrack.setVolume(30.0f);

    Sound switchinmenu;
    switchinmenu.setBuffer(beep);
    Sound lasershoot;
    lasershoot.setBuffer(laser);
    Sound bombshoot;
    bombshoot.setBuffer(bomb);

    // clocki
    Clock clock;
    Clock clock1;
    Clock clock2;
    Clock clock3;
    Clock LaserCD;
    Clock BombCD;
    Clock bossShootCD;

    // poziom trudnosci
    float enemyCD = 1;
    float enemySpawnCD = 10;
    float shipLaserCD = 0.1;
    float shipBombCD = 1;

    // gracz
    Ship player(0);
    player.set_location(350.0f, 500.0f);

    // enemy
    vector <Enemy*> enemies;
    int numberOfEnemies = 5;
    vector <EnemyLaser*> en_lasers;

    // boss
    Boss boss(400, 0);
    vector <BossLaser*> boss_lasersL;
    vector <BossLaser*> boss_lasersS;
    vector <BossLaser*> boss_lasersR;
    int check = 0;
    int bossThreshold = 500;
    float bossCD = 3;

    // lasery
    vector <Laser*> lasers;
    // bomby
    vector <Bomb*> bombs;

    // zmiana broni
    int zPressed = 0;

    //opcje domyslne w menu opcje
    int chooselvl = 1;
    int chooseNick = 5;
    
    Event event; // event -> zamkniecie okienka
    while (window.isOpen())
    {
        while (true && wyj == 0) // to jest main menu
        {
            Event event; // Obsluga zdarzen
            if (window.pollEvent(event))
            {
                switch (event.type)
                {
                case Event::Closed: window.close(); return 0; break;
                case Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case Keyboard::Up: menu.MoveUpper(); switchinmenu.play(); break;
                    case Keyboard::Down: menu.MoveDown(); switchinmenu.play(); break;
                    case Keyboard::Enter:
                        switchinmenu.play();
                        switch (menu.GetPressedItemID())
                        {
                        case 0:
                            wyj = 1;
                            clock.restart();
                            clock1.restart();
                            clock2.restart();
                            clock3.restart();
                            LaserCD.restart();
                            BombCD.restart();
                            enemies.clear();
                            en_lasers.clear();
                            lasers.clear();
                            bombs.clear();
                            player.setScore(0);
                            bossShootCD.restart();
                            check = 0;
                            boss.getShape().setPosition(400, 0);
                            if (shipchoosen == 0)
                            {
                                player.setHP(10);
                                shipLaserCD = 0.1;
                                shipBombCD = 1;
                            }
                            else if (shipchoosen == 1)
                            {
                                player.setHP(20);
                                shipLaserCD = 0.3;
                                shipBombCD = 0.5;
                            }
                            else if (shipchoosen == 2)
                            {
                                player.setHP(30);
                                shipLaserCD = 0.2;
                                shipBombCD = 2;
                            }
                            
                            break;
                        case 1: cout << "Opcje" << endl; wyj = 2;  break;
                        case 2: cout << "Statek" << endl; wyj = 3; break;
                        case 3: cout << "Jak grac" << endl; wyj = 4; break;
                        case 4: window.close(); return 0;  break;
                        }
                    }
                }
            }
            if (wyj != 0)
                break;

            window.clear();
            menu.draw(window);
            window.display();
        }
        while (true && wyj == 2) //to sa opcje
        {
            int tmp = -5;
            optionsmenu.choosenpositions(chooselvl, chooseNick);
            Event event; // Obsluga zdarzen
            if (window.pollEvent(event))
            {
                switch (event.type)
                {
                case Event::Closed: window.close(); return 0; break;
                case Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case Keyboard::Up: optionsmenu.MoveUpper(); switchinmenu.play(); break;
                    case Keyboard::Down: optionsmenu.MoveDown(); switchinmenu.play(); break;
                    case Keyboard::Enter: tmp = optionsmenu.GetPressedItemID(); switchinmenu.play(); break;
                    case Keyboard::Escape: wyj = 0; switchinmenu.play(); break;
                    }
                }
            }
            if (tmp != -5 && tmp != 0 && tmp != 4) 
            {
                if (tmp < 4)
                {
                    chooselvl = tmp;
                    if (chooselvl == 1)
                    {
                        enemyCD = 1;
                        enemySpawnCD = 10;
                        bossThreshold = 500;
                        boss.setHP(20);
                        bossCD = 3;
                    }
                    if (chooselvl == 2)
                    {
                        enemyCD = 0.5;
                        enemySpawnCD = 5;
                        bossThreshold = 1500;
                        boss.setHP(100);
                        bossCD = 1;
                    }
                    if (chooselvl == 3)
                    {
                        enemyCD = 0.1;
                        enemySpawnCD = 2;
                        bossThreshold = 3000;
                        boss.setHP(500);
                        bossCD = 0;
                    }
                }
                else
                {
                    chooseNick = tmp;
                }
            }
            if (wyj == 0)
                break;
            window.clear();
            optionsmenu.draw(window);
            window.display();
        }

        while (true && wyj == 3) //wybor statku
        {
            Event event; // Obsluga zdarzen
            if (window.pollEvent(event))
            {
                switch (event.type)
                {
                case Event::Closed: window.close(); return 0; break;
                case Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case Keyboard::Up: selectionofship.MoveUpper(); switchinmenu.play(); break;
                    case Keyboard::Down: selectionofship.MoveDown(); switchinmenu.play(); break;
                    case Keyboard::Enter: shipchoosen = selectionofship.GetPressedItemID(); switchinmenu.play(); wyj = 0; break;
                    case Keyboard::Escape: wyj = 0; switchinmenu.play(); break;
                    }
                }
            }
            if (wyj == 0)
                break;

            window.clear();
            selectionofship.draw(window);
            window.display();
        }

        while (true && wyj == 4) // TO JEST JAK GRAC
        {
            Event event; // Obsluga zdarzen
            if (window.pollEvent(event))
            {
                switch (event.type)
                {
                case Event::Closed: window.close(); return 0; break;
                case Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case Keyboard::Escape: wyj = 0; switchinmenu.play(); break;

                    }
                }
            }
            if (wyj == 0) {
                break;
            }

            window.clear();
            howplay.draw(window);
            window.pollEvent(event);
            window.display();
        }

        while (true && wyj == 21) // TO JEST MENU PO PRZEGRANEJ
        {
            Event event; // Obsluga zdarzen
            if (window.pollEvent(event))
            {
                switch (event.type)
                {
                case Event::Closed: window.close(); return 0; break;
                case Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case Keyboard::Escape: wyj = 0; switchinmenu.play(); break;
                    }
                }
            }
            if (wyj == 0) {
                break;
            }

            window.clear();
            loser.draw(window);
            window.pollEvent(event);
            window.display();
        }

        while (true && wyj == 37) // TO JEST MENU PO WYGRANEJ
        {
            Event event; // Obsluga zdarzen
            if (window.pollEvent(event))
            {
                switch (event.type)
                {
                case Event::Closed: window.close(); return 0; break;
                case Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case Keyboard::Escape: wyj = 0; switchinmenu.play(); break;

                    }
                }
            }
            if (wyj == 0) {
                break;
            }

            window.clear();
            winer_winner_chicken_dinner.draw(window);
            window.pollEvent(event);
            window.display();
        }

        while (true && wyj == 1) //TO JEST GRA
        {
            player.changetexture(shipchoosen);
            window.clear(Color::Black); // kolor tla
            window.draw(backgroundGame);
            window.pollEvent(event); // ze da sie okienko przeciagac 

            if (event.type == Event::Closed) // zamykanie okienka
            {
                window.close();
                return 0;
                break;
            }

            string scorestr = to_string(player.getScore());
            display[0].setString("points: " + scorestr);
            window.draw(display[0]);

            string showHP;
            showHP = to_string(player.getHP());
            display[1].setString("HP: " + showHP);
            window.draw(display[1]);

            // player
            player.draw(window);

            // poruszanie sie lewo prawo
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right)
            {
                if (player.getShape().getPosition().x + player.getShape().getGlobalBounds().width < 800)
                {
                    player.getShape().move(4.f, 0.f);
                }
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left)
            {
                if (player.getShape().getPosition().x > 0)
                {
                    player.getShape().move(-4.f, 0.f);
                }
            }

            //enemy spawning
            int place = 100;

            Time elapsed = clock.getElapsedTime();
            Time elapsed1 = clock1.getElapsedTime();
            // poczatkowy rzad enemy
            if (enemies.size() == 0 && player.getScore() < bossThreshold)
            {
                for (int i = 0; i < numberOfEnemies; i++)
                {
                    Enemy* enemy = new Enemy(place, 100);
                    enemies.push_back(enemy);
                    place += 150;
                }
            }
            // bossik :>
            else if (player.getScore() >= bossThreshold)
            {
                if (enemies.size() == 0)
                {
                    boss.draw(window);
                    if (boss.getShape().getPosition().y <= 200 && check == 0)
                    {
                        if (boss.getBossVelocityV() < 0)
                            boss.revBossVelocityV();
                        boss.move_vertical(boss.getBossVelocityV());
                    }
                    else
                    {
                        check = 1;
                        boss.move_horizontal(boss.getBossVelocityH(), boss.getBossVelocityV());
                        if (boss.getShape().getPosition().y >= 200.3)
                        {
                            boss.revBossVelocityV();
                        }
                        if (boss.getShape().getPosition().y <= 49.7)
                        {
                            boss.revBossVelocityV();
                        }
                        if (boss.getShape().getPosition().x >= 800)
                        {
                            boss.revBossVelocityH();
                        }
                        if (boss.getShape().getPosition().x <= 0)
                        {
                            boss.revBossVelocityH();
                        }
                        //laser po uderzeniu bossa
                        for (int i = 0; i < lasers.size(); i++)
                        {
                            if (lasers[i]->getShape().getPosition().y <= boss.getShape().getPosition().y + 75 &&
                                lasers[i]->getShape().getPosition().y >= boss.getShape().getPosition().y - 75 &&
                                lasers[i]->getShape().getPosition().x <= boss.getShape().getPosition().x + 75 &&
                                lasers[i]->getShape().getPosition().x >= boss.getShape().getPosition().x - 75)
                            {
                                lasers.erase(lasers.begin() + i);
                                boss.setHP(boss.getHP() - lasers[i]->getDamage());
                            }
                        }
                        // bomba po uderzeniu bossa
                        for (int i = 0; i < bombs.size(); i++)
                        {
                            if (bombs[i]->getShape().getPosition().y <= boss.getShape().getPosition().y + 75 &&
                                bombs[i]->getShape().getPosition().y >= boss.getShape().getPosition().y - 75 &&
                                bombs[i]->getShape().getPosition().x <= boss.getShape().getPosition().x + 75 &&
                                bombs[i]->getShape().getPosition().x >= boss.getShape().getPosition().x - 75)
                            {
                                bombs.erase(bombs.begin() + i);
                                boss.setHP(boss.getHP() - bombs[i]->getDamage());
                            }
                        }
                        // boss strzelanie
                        Time elapsedBoss = bossShootCD.getElapsedTime();
                        if (elapsedBoss.asSeconds() >= bossCD)
                        {
                            BossLaser* boss_laserL = new BossLaser(boss.getShape().getPosition().x, boss.getShape().getPosition().y + 75);
                            boss_lasersL.push_back(boss_laserL);
                            BossLaser* boss_laserS = new BossLaser(boss.getShape().getPosition().x, boss.getShape().getPosition().y + 75);
                            boss_lasersS.push_back(boss_laserS);
                            BossLaser* boss_laserR = new BossLaser(boss.getShape().getPosition().x, boss.getShape().getPosition().y + 75);
                            boss_lasersR.push_back(boss_laserR);
                            bossShootCD.restart();
                        }
                        for (int i = 0; i < boss_lasersL.size(); i++)
                        {
                            boss_lasersL[i]->update_position(-1 * boss_lasersL[0]->getVelocity(), boss_lasersL[0]->getVelocity());
                            boss_lasersL[i]->draw(window);

                            if (boss_lasersL[i]->getShape().getPosition().y <= player.getShape().getPosition().y + 50 &&
                                boss_lasersL[i]->getShape().getPosition().y >= player.getShape().getPosition().y &&
                                boss_lasersL[i]->getShape().getPosition().x >= player.getShape().getPosition().x &&
                                boss_lasersL[i]->getShape().getPosition().x <= player.getShape().getPosition().x + 100)
                            {
                                boss_lasersL.erase(boss_lasersL.begin() + i);
                                player.setHP(player.getHP() - boss_lasersL[i]->getDamage());
                            }
                        }
                        for (int i = 0; i < boss_lasersS.size(); i++)
                        {
                            boss_lasersS[i]->update_position(0, 1.41 * boss_lasersS[0]->getVelocity());
                            boss_lasersS[i]->draw(window);

                            if (boss_lasersS[i]->getShape().getPosition().y <= player.getShape().getPosition().y + 50 &&
                                boss_lasersS[i]->getShape().getPosition().y >= player.getShape().getPosition().y &&
                                boss_lasersS[i]->getShape().getPosition().x >= player.getShape().getPosition().x &&
                                boss_lasersS[i]->getShape().getPosition().x <= player.getShape().getPosition().x + 100)
                            {
                                boss_lasersS.erase(boss_lasersS.begin() + i);
                                player.setHP(player.getHP() - boss_lasersS[i]->getDamage());
                            }
                        }
                        for (int i = 0; i < boss_lasersR.size(); i++)
                        {
                            boss_lasersR[i]->update_position(1 * boss_lasersR[0]->getVelocity(), boss_lasersR[0]->getVelocity());
                            boss_lasersR[i]->draw(window);
                       
                            if (boss_lasersR[i]->getShape().getPosition().y <= player.getShape().getPosition().y + 50 &&
                                boss_lasersR[i]->getShape().getPosition().y >= player.getShape().getPosition().y &&
                                boss_lasersR[i]->getShape().getPosition().x >= player.getShape().getPosition().x &&
                                boss_lasersR[i]->getShape().getPosition().x <= player.getShape().getPosition().x + 100)
                            {
                                boss_lasersR.erase(boss_lasersR.begin() + i);
                                player.setHP(player.getHP() - boss_lasersR[i]->getDamage());
                            }
                        }
                        string bossHP;
                        bossHP = to_string((int)boss.getHP());
                        displayBossHP[0].setString("BOSS HP: " + bossHP);
                        window.draw(displayBossHP[0]);
                    }
                }
                if (boss.getHP() <= 0)
                {
                    enemies.clear();
                    en_lasers.clear();
                    boss_lasersL.clear();
                    boss_lasersS.clear();
                    boss_lasersR.clear();
                    lasers.clear();
                    bombs.clear();
                    loser.sendScore(player.getScore());
                    player.setScore(0);
                    if (chooselvl == 1)
                        boss.setHP(20);
                    if (chooselvl == 1)
                        boss.setHP(100);
                    if (chooselvl == 1)
                        boss.setHP(20);
                    clock.restart();
                    clock1.restart();
                    clock2.restart();
                    clock3.restart();
                    LaserCD.restart();
                    BombCD.restart();
                    bossShootCD.restart();
                    wyj = 37;
                    break;
                }
            }
            // kolejne rzedy enemy
            else
            {
                for (int i = 0; i < numberOfEnemies; i++)
                {
                    if (elapsed.asSeconds() >= enemySpawnCD)
                    {
                        Enemy* enemy = new Enemy(place, 100);
                        enemies.push_back(enemy);
                        place += 150;
                        clock.restart();
                    }
                }
                if (enemies.size() <= 5)
                {
                    for (int i = 0; i < enemies.size(); i++)
                    {

                        if (elapsed1.asSeconds() >= enemySpawnCD)
                        {
                            enemies[i]->update_position();
                            clock1.restart();
                        }
                    }
                }
                else
                    for (int i = 0; i < enemies.size() - 5; i++)
                    {

                        if (elapsed1.asSeconds() >= enemySpawnCD)
                        {
                            enemies[i]->update_position();
                            clock1.restart();
                        }
                    }
            }

            Time elapsed2 = clock2.getElapsedTime();
            for (int i = 0; i < enemies.size(); i++)
            {
                enemies[i]->draw(window);
                // poziome poruszanie
                enemies[i]->move_horizontal(enemies[i]->getEnemyVelocity());
                if (elapsed2.asSeconds() >= 1.5)
                {
                    enemies[i]->setEnemyVelocity();
                    clock2.restart();
                }
                // enemy poza ekranem
                if (enemies[i]->getShape().getPosition().y >= 500)
                {
                    enemies.erase(enemies.begin() + i);
                    player.setHP(0);
                }
            }
            // enemy strzelanie
            Time elapsed3 = clock3.getElapsedTime();
            if (enemies.size() != 0 && player.getScore() < bossThreshold)
            {
                if (elapsed3.asSeconds() >= enemyCD)
                {
                    clock3.restart();
                    int a = rand() % enemies.size();
                    EnemyLaser* en_laser = new EnemyLaser(enemies[a]->getShape().getPosition().x, enemies[a]->getShape().getPosition().y + 40);
                    en_lasers.push_back(en_laser);

                }
                // iteracja po wektorze laserów wrogów
                for (int i = 0; i < en_lasers.size(); i++)
                {
                    en_lasers[i]->update_position();
                    en_lasers[i]->draw(window);
                    // laser wroga po uderzeniu w gracza
                    if (en_lasers[i]->getShape().getPosition().y <= player.getShape().getPosition().y + 50 &&
                        en_lasers[i]->getShape().getPosition().y >= player.getShape().getPosition().y &&
                        en_lasers[i]->getShape().getPosition().x >= player.getShape().getPosition().x &&
                        en_lasers[i]->getShape().getPosition().x <= player.getShape().getPosition().x + 100)
                    {
                        en_lasers.erase(en_lasers.begin() + i);
                        player.setHP(player.getHP() - en_lasers[i]->getDamage());
                    }
                    // laser wroga po wyjsciu poza ekran
                    if (en_lasers[i]->getShape().getGlobalBounds().height > 700)
                    {
                        en_lasers.erase(en_lasers.begin() + i);
                    }
                }
            }
            
            // strzelanie

            // zmiana broni
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Z)
            {
                if (zPressed == 0)
                    zPressed = 1;
                else if (zPressed == 1)
                    zPressed = 0;
            }

            Time elapsedLaserCD = LaserCD.getElapsedTime();
            Time elapsedBombCD = BombCD.getElapsedTime();
            switch (zPressed)
            {
            case 0:
                // dodanie pojedynczych laserów do wektora
                if (event.type == Event::KeyPressed && Event::KeyReleased && event.key.code == Keyboard::Space && elapsedLaserCD.asSeconds() >= shipLaserCD)
                {
                    lasershoot.play();
                    Laser* laser = new Laser(player.getShape().getPosition().x + 50, player.getShape().getPosition().y);
                    lasers.push_back(laser);
                    LaserCD.restart();
                }
                break;
            case 1:
                // dodanie pojedynczych bomb do wektora
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space && elapsedBombCD.asSeconds() >= shipBombCD)
                {
                    bombshoot.play();
                    Bomb* bomb = new Bomb(player.getShape().getPosition().x + 50, player.getShape().getPosition().y);
                    bombs.push_back(bomb);
                    BombCD.restart();
                }
                break;
            default:
                break;
            }

            // iteracja po wektorze laserów
            for (int i = 0; i < lasers.size(); i++)
            {
                lasers[i]->update_position();
                lasers[i]->draw(window);

                // laser poza ekranem
                if (lasers[i]->getShape().getGlobalBounds().height < 0)
                {
                    lasers.erase(lasers.begin() + i);
                }

                // laser po uderzeniu wroga

                // iteracja po wektorze wrogów
                for (int j = 0; j < enemies.size(); j++)
                {
                    if (lasers[i]->getShape().getPosition().y == enemies[j]->getShape().getPosition().y + 40 &&
                        lasers[i]->getShape().getPosition().x >= enemies[j]->getShape().getPosition().x - 40 &&
                        lasers[i]->getShape().getPosition().x <= enemies[j]->getShape().getPosition().x + 40)
                    {
                        lasers.erase(lasers.begin() + i);
                        enemies[j]->setHP(enemies[j]->getHP() - lasers[i]->getDamage());
                    }
                    if (enemies[j]->getHP() <= 0)
                    {
                        enemies.erase(enemies.begin() + j);
                        player.givePoints();
                    }
                }
            }
            // iteracja po wektorze bomb
            for (int i = 0; i < bombs.size(); i++)
            {
                bombs[i]->update_position();
                bombs[i]->draw(window);

                // bomba poza ekranem
                if (bombs[i]->getShape().getGlobalBounds().height < 0)
                {
                    bombs.erase(bombs.begin() + i);
                }

                // bomba po uderzeniu wroga

                // iteracja po wektorze wrogów
                for (int j = 0; j < enemies.size(); j++)
                {
                    if (bombs[i]->getShape().getPosition().y == enemies[j]->getShape().getPosition().y + 40 &&
                        bombs[i]->getShape().getPosition().x >= enemies[j]->getShape().getPosition().x - 40 &&
                        bombs[i]->getShape().getPosition().x <= enemies[j]->getShape().getPosition().x + 40)
                    {
                        bombs.erase(bombs.begin() + i);
                        enemies[j]->setHP(enemies[j]->getHP() - bombs[i]->getDamage());
                    }
                    if (enemies[j]->getHP() <= 0)
                    {
                        enemies.erase(enemies.begin() + j);
                        player.givePoints();
                    }
                }
            }
            if (player.getHP() <= 0)
            {
                enemies.clear();
                en_lasers.clear();
                lasers.clear();
                bombs.clear();
                loser.sendScore(player.getScore());
                player.setScore(0);
                wyj = 21;
                break;
            }
            window.display();
        }
    }
    return 0;
}
