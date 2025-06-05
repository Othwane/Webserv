/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mime.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unky0 <unky0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:27:33 by omajdoub          #+#    #+#             */
/*   Updated: 2025/06/05 02:39:40 by unky0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../server/Server.hpp"
#include "../utils.hpp"

class Mime
{
    private:
        std::ifstream _file;
        std::map<std::vector<std::string>, std::string> _mimeMap;
    public:
        Mime();
        ~Mime();
        const std::ifstream& getFile() const;
        const std::string getContentType(const std::string& extension) const;
        // const std::string& getFileContent() const;
        const std::map<std::vector<std::string>, std::string>& getMimeMap() const;
};

