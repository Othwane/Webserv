/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unky0 <unky0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:58:46 by omajdoub          #+#    #+#             */
/*   Updated: 2025/06/05 02:40:14 by unky0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <poll.h>
#include <vector>
#include <vector>
#include <fstream>
#include <map>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>


class Server
{
private:
    int sockfd;
    struct sockaddr_in addr;
    socklen_t addrlen;
    std::vector<pollfd> clientSockets;
    int port;

public:
    Server(int port, const std::string& host);
    /************ Getters ***************/
    int getPort();
    int getSockfd();
    std::vector<pollfd> &getClientSockets();
    const sockaddr_in &getAddr() const;
    socklen_t &getAddrlen();
    
    /* Setters*/
    void setPort(int port);

    pollfd addClient(int clientFd, int flag);
};