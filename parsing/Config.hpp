/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unky0 <unky0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:15:53 by omajdoub          #+#    #+#             */
/*   Updated: 2025/06/05 02:39:28 by unky0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../server/Server.hpp"
#include "../parsing/Mime.hpp"
#include "../parsing/Parser.hpp"

class Client;

class Config: public Mime, public Parser
{
    private:
        std::vector<int> port;
        std::string serverName;
        std::vector<std::string> host;
        std::string root;
        std::string index;
        std::vector<std::string> errorPage;
        std::string autoIndex;
        std::string clientMaxBodySize;
        std::string uploadDir;
        std::map<std::string, int> allowedMethods;
        std::map<std::string, std::string> isErrorPage;
        std::vector<std::string> redirect;
        
        const std::string& filePath;
        static std::string nullFile; //Contains nothing

        std::vector<std::pair<std::string, std::vector<std::string> > > globalDirectives;
        std::vector<std::pair<std::string, std::pair<std::string, std::vector<std::string> > > > locations;
        std::vector<std::vector<std::pair<std::string, std::vector<std::string> > > > servers;
        
        std::map<int, std::string> portMap;
    public:
        Config();
        Config(const std::string& file);
        
        Config(const Config& cpy);
        Config& operator=(const Config& cpy);

        // std::string getFileContent(const std::string& filename) const;
        
        /************ SETTERS ************/
        void setPort();
        void setHost();
        void setServerName(int isLocation, const std::string &uri, const std::string& port);
        void setRoot(int isLocation, const std::string& uri, const std::string& port);
        void setErrorPage(int isLocation, const std::string& uri, const std::string& port);
        void setIndex(int isLocation, const std::string& uri, const std::string& port);
        void setAutoIndex(int isLocation, const std::string& uri, const std::string& port);
        void setClientMaxBodySize(int isLocation, const std::string& uri, const std::string& port);
        void setUploadDir(int isLocation, const std::string& uri, const std::string& port);
        void setAllowedMethods(int isLocation, const std::string &uri, const std::string& port);
        void setRedirect(int isLocation, const std::string &uri, const std::string& port);
        void defineErrorPage(int isLocation, const std::string &uri, const std::string& port);
        
        void setPortMap(int port);

        /************ GETTERS ************/
        const std::vector<int> getPort();
        const std::string getHost(int port);
        const std::string getServerName();
        const std::string getRoot();
        const std::vector<std::string> getErrorPage();
        const std::string getIndex();
        const std::string getAutoIndex();
        const std::string getClientMaxBodySize();
        const std::string getUploadDir();
        const std::map<std::string, int> getAllowedMethods();
        const std::vector<std::string> getRedirect();
        
        std::map<int, std::string> getPortMap();

        std::string getErrorPage(const std::string& errorCode, const std::string& uri, int location);
        std::string getErrorCode();
        const std::map<std::string, std::string> getIsErrorPage();
        int isLocation(const std::string& uri, const std::string& port);
        
        size_t getConfigLocationIndex(const std::string &clientUri, const std::string& port);
        size_t getPortIndex(const std::string &port);
};