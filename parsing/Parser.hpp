/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unky0 <unky0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 22:48:15 by omajdoub          #+#    #+#             */
/*   Updated: 2025/06/05 02:39:47 by unky0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

class Parser
{
    private:
        const std::string filePath;
        std::vector<std::string> allowedDirectives;

        std::vector<std::pair<std::string, std::pair<std::string, std::vector<std::string> > > > locations;
        std::vector<std::pair<std::string, std::vector<std::string> > > globalDirectives;
        
        std::vector<std::vector<std::pair<std::string, std::vector<std::string> > > > allServers;
    public:
        Parser();
        ~Parser();
        Parser(const std::string& filePath);
        void parse();
        std::vector<std::pair<std::string, std::vector<std::string> > > parseServer(std::string &serverBlock);
        void checkGlobalDuplicates(const std::vector<std::string>&);
        void checkLocationsDuplicates(const std::vector<std::string>&);
        int checkSyntax(std::vector<std::pair<std::string, std::vector<std::string> > > directives);
        void setServerDirectives(std::vector<std::pair<std::string, std::vector<std::string> > >& directives);
        // void setDefaultDirectives(const std::vector<std::string>& keys, int& port, std::vector<std::pair<std::string, std::vector<std::string> > >& directives);
        //******** GETTERS *********
        std::vector<std::pair<std::string, std::pair<std::string, std::vector<std::string> > > > getLocations();
        std::vector<std::pair<std::string, std::vector<std::string> > > getGlobalDirectives();
        std::vector<std::vector<std::pair<std::string, std::vector<std::string> > > > getAllServers();

};
        int checkListen(const std::vector<std::string>& keys);