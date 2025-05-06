#include "DelayConfig.h"

DelayConfig::DelayConfig() {}

DelayConfig::DelayConfig(const std::string filename) {
	std::ifstream configFile(filename);
	if (configFile) {
		configFile >> readDelay >> writeDelay >> moveDelay >> rewindDelayPerPosition;
	}
	else {
		std::cerr << "Cannot open config file, default DelayConfig with 0 ms delays will be used";
	}
}

size_t DelayConfig::getReadDelay() const {
	return readDelay;
}

size_t DelayConfig::getWriteDelay() const {
	return writeDelay;
}

size_t DelayConfig::getMoveDelay() const {
	return moveDelay;
}

size_t DelayConfig::getRewindDelayPerPosition() const {
	return rewindDelayPerPosition;
}