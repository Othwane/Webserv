/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientHandler.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unky0 <unky0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 02:07:38 by omajdoub          #+#    #+#             */
/*   Updated: 2025/06/05 02:39:12 by unky0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Client.hpp"
#include "../utils.hpp"
#include "../parsing/Mime.hpp"
#include "../Cgi/Cgi.hpp"

std::string parseRequest(Client& client, const std::string &request);
std::string handleRequest(Client& client, Config& config, std::string &request);
std::string readFile(std::string filePath);
int getHeaders(const std::string& request, Client& client);
