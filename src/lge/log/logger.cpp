/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "lge/log/logger.h"

#include <stdio.h>
#include <time.h>
#include <map>
#include <vector>
#include <fstream>
#include <cstring>

#include "lge/util/StringUtil.h"

namespace lge
{

namespace log
{

const char* LOG_FILE = "log.log";

const char* HANDLERS = "HANDLERS";
const char* OUTPUT_DIRECTORY = "OUTPUT_DIRECTORY";
const char* LEVEL = "LEVEL";

const char COMMENT_SYMBOL = '#';
const char VALUE_DELIMITER = ',';
const char OPTION_DELIMITER = '=';

const char* CONSOLE_HANDLER = "console";
const char* FILE_HANDLER = "file";

enum Level
{
	DEBUG = 0, INFO, WARN, ERROR
};

std::map<Level, const char*> initLevels()
{
	std::map<Level, const char*> map;
	map[DEBUG] = "DEBUG";
	map[INFO] = "INFO";
	map[WARN] = "WARN";
	map[ERROR] = "ERROR";
	return map;
}

std::map<Level, const char*> levels = initLevels();

struct Config
{
	bool console;
	bool file;
	std::string outputDir;
	Level level;
	
	Config()
		: console(true), file(false), outputDir("."), level(INFO)
	{
	}
	
};

// From the compiler
#ifndef CONFIGFILE
	#define CONFIGFILE "../../etc/logger.config"
	#define CONFIG_FILE_SPECIFIED 0
#else
	#define CONFIG_FILE_SPECIFIED 1
#endif

Config config;

bool initialized = false;

std::ofstream output;

std::string& getOptions(const std::string& line, std::string& options)
{
	unsigned int separatorPos = strlen(HANDLERS);
	if (line.size() > separatorPos &&
			line[separatorPos] == OPTION_DELIMITER) {
		options = line.substr(separatorPos+1);
	}
	else {
		options = "";
	}
	return options;
}

void setCustomConfig(const std::vector<std::string>& handlers,
		const std::string& outputDir, const std::string& level)
{
	if (handlers.size() > 0) {
		bool console = false;
		bool file = false;
		for (std::vector<std::string>::const_iterator iter = handlers.begin();
				iter != handlers.end();
				++iter) {
			if ((*iter).compare(CONSOLE_HANDLER) == 0) {
				console = true;
			}
			else if ((*iter).compare(FILE_HANDLER) == 0) {
				file = true;
			}
		}
		if (console == false) {
			config.console = false;
		}
		if (file == true) {
			config.file = true;
		}
	}
	
	if (!outputDir.empty()) {
		config.outputDir = outputDir;
	}
	if (!level.empty()) {
		std::string uppercase;
		for (std::map<Level, const char*>::const_iterator iter = levels.begin();
				iter != levels.end();
				++iter) {
			uppercase = lge::util::toUpperCase(level, uppercase);
			if (strcmp(iter->second, uppercase.c_str()) == 0) {
				config.level = iter->first;
			}
		}
	}
}

void loadConfig()
{
	if (!CONFIG_FILE_SPECIFIED) {
		printf("The config file has not been specified. Using default location '%s'.\n"
				"To specify a custom location, use -DCONFIGFILE\n", CONFIGFILE);
	}
	std::ifstream file(CONFIGFILE);
	if (file.is_open()) {
		std::vector<std::string> handlers;
		std::string outputDirectory;
		std::string level;
		
		bool error = false;
		std::string line;
		while (getline(file, line)) {
			if (!line.empty() && line[0] != COMMENT_SYMBOL) {
				if (line.find(HANDLERS) == 0) {
					std::string options;
					options = getOptions(line, options);
					if (!options.empty()) {
						handlers = lge::util::split(options, VALUE_DELIMITER, handlers);
					}
					else {
						error = true;
						break;
					}
				}
				else if (line.find(OUTPUT_DIRECTORY) == 0) {
					unsigned int separatorPos = strlen(OUTPUT_DIRECTORY);
					if (line.size() > separatorPos) {
						outputDirectory = line.substr(separatorPos+1);
					}
				}
				else if (line.find(LEVEL) == 0) {
					unsigned int separatorPos = strlen(LEVEL);
					if (line.size() > separatorPos) {
						level = line.substr(separatorPos+1);
					}
				}
				// Malformed file
				else {
					error = true;
					break;
				}
			}
		}
		
		if (!error) {
			setCustomConfig(handlers, outputDirectory, level);
		}
		else {
			printf("Errors found when loading logger config\n");
		}
	}
	initialized = true;
}

void init()
{
	if (config.file) {
		std::string fullPath = config.outputDir;
		if (fullPath[fullPath.size()-1] != '/') {
			fullPath.append("/");
		}
		fullPath.append(LOG_FILE);
		output.open(fullPath.c_str(), std::ofstream::out | std::ofstream::app);
	}
}

const int TIME_BUFFER_SIZE = 20;
char timeBuffer[TIME_BUFFER_SIZE];

void log(Level level, const char* module, const char* message)
{
	if (!initialized) {
		loadConfig();
		init();
	}
	
	if (config.level <= level) {
		time_t rawtime;
		time (&rawtime);
		strftime(timeBuffer, TIME_BUFFER_SIZE, "%F %T", localtime(&rawtime));
		
		if (config.console) {
			printf("%s %s: [%s] %s\n", timeBuffer, levels[level], module, message);
		}
		if (config.file) {
			output << timeBuffer << " " << levels[level] << ": [" << module << "] " <<
					message << "\n";
		}
	}
}

void debug(const char* module, const char* message)
{
	log(DEBUG, module, message);
}

void info(const char* module, const char* message)
{
	log(INFO, module, message);
}

void warn(const char* module, const char* message)
{
	log(WARN, module, message);
}

void error(const char* module, const char* message)
{
	log(ERROR, module, message);
}

} // namespace

} // namespace
