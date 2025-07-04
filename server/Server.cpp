/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unky0 <unky0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:08:33 by omajdoub          #+#    #+#             */
/*   Updated: 2025/06/05 02:37:48 by unky0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <arpa/inet.h>
Server::Server(int port, const std::string& host)
{
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sockfd == 0)
    {
        throw std::runtime_error("Socket creation failed");
    }

    this->addrlen = sizeof(this->addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host.c_str());

    int opt = 1;
    setsockopt(this->getSockfd(), SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if (bind(this->getSockfd(), (struct sockaddr *)&addr, sizeof(this->getAddr())) < 0)
    {
        throw std::runtime_error("Bind failed");
    }
    if (listen(this->getSockfd(), 1000) < 0)
    {
        throw std::runtime_error("Listen failed");
    }
}

int Server::getSockfd()
{
    return this->sockfd;
}

int Server::getPort()
{
    return this->port;
}

void Server::setPort(int newPort)
{
    this->port = newPort;
}

const sockaddr_in &Server::getAddr() const
{
    return this->addr;
}

socklen_t &Server::getAddrlen()
{
    return this->addrlen;
}

std::vector<pollfd> &Server::getClientSockets()
{
    return this->clientSockets;
}

int setNonBlocking(int sockfd)
{
    int flags = fcntl(sockfd, F_GETFL);
    if (flags < 0)
        throw std::runtime_error("Error getting socket flags");
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) < 0)
        throw std::runtime_error("Error setting socket to non-blocking mode");
    return 0;
}

pollfd Server::addClient(int clientFd, int flag)
{
    struct pollfd clientSocket;
    clientSocket.fd = clientFd;
    if (flag)
        clientSocket.events = POLLIN | POLLHUP | POLLERR;
    else
        clientSocket.events = POLLIN | POLLOUT;
    setNonBlocking(clientFd);
    this->clientSockets.push_back(clientSocket);
    return clientSocket;
}
