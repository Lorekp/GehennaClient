#include "ConnectionHandler.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <SFML/Network.hpp>
#include <cassert>

ConnectionHandler* ConnectionHandler::sInstance = nullptr;

ConnectionHandler::ConnectionHandler() : PORT(53000), IPADDRESS("192.168.178.44") {
    assert(sInstance == nullptr);
    sInstance = this;

    connected = false;

    receiveThread = nullptr;
    connectToServerThread = new std::thread(&ConnectionHandler::connectToServer, this);
    updateThread = nullptr;
}

ConnectionHandler::~ConnectionHandler() {
    if (receiveThread && receiveThread->joinable()) {
        receiveThread->join();
    }
    if (connectToServerThread && connectToServerThread->joinable()) {
        connectToServerThread->join();
    }
    if (updateThread && updateThread->joinable()) {
        updateThread->join();
    }
}

void ConnectionHandler::connectToServer() {
    int delay = 5; // Start with a 5 second delay
    // ReSharper disable once CppTooWideScopeInitStatement
    constexpr int maxDelay = 320; // Maximum delay of 320 seconds

    while (!connected) {
        if (socket.connect(IPADDRESS, PORT) != sf::Socket::Done) {
            std::cerr << "Error connecting to server" << std::endl;
        }
        else {
            std::cout << "Connected to server " << IPADDRESS << " on port " << PORT << std::endl;

            std::string key;

            std::ifstream keyFile(".\\data\\key.txt");

            if (keyFile.is_open()) {
                std::getline(keyFile, key);
                keyFile.close();
            }
            else {
                std::cout << "Couldn't open key.txt file!" << std::endl;
            }

            sf::Packet packet;
            packet << key;

            if (socket.send(packet) != sf::Socket::Done) {
                std::cerr << "Failed to send key to server." << std::endl;
            }
            else {
                std::cout << "Key sent to server for authentication. Waiting for response." << std::endl;
                while (true) {
                    sf::Packet packet;
                    if (socket.receive(packet) == sf::Socket::Done) {
                        std::string message;
                        packet >> message;
                        if (message == "authenticated") {
                            std::cout << "Client authenticated by Server." << std::endl;
                            connected = true;
                            break;
                        }
                        else {
                            std::cout << "Client denied by Server." << std::endl;
                        }
                    }
                }
            }
        }
        if (!connected) {
            // Wait for the specified delay
            std::this_thread::sleep_for(std::chrono::seconds(delay));
        }

        // Double the delay, but do not exceed the maximum delay
        if (delay < maxDelay) {
            delay *= 2;
            if (delay > maxDelay) {
                delay = maxDelay;
            }
        }
    }
    if (connected) {
        receiveThread = new std::thread(&ConnectionHandler::receiveMessages, this);
        updateThread = new std::thread(&ConnectionHandler::update, this);
    }
}

void ConnectionHandler::receiveMessages() {
    while (true) {
        sf::Packet packet;
        if (socket.receive(packet) == sf::Socket::Done) {
            std::string message;
            packet >> message;
            std::cout << "Received message: " << message << std::endl;
        }
    }
}

void ConnectionHandler::update() {
    while (true) {
        std::cout << "Enter message to send: ";
        std::string message;
        std::getline(std::cin, message);

        sf::Packet packet;
        packet << message;


        if (socket.send(packet) != sf::Socket::Done) {
            std::cerr << "Error sending message" << std::endl;
        }
        else {
            std::cout << "Message sent: " << message << std::endl;
        }
    }
}
