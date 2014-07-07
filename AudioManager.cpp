#include "AudioManager.hpp"

#include <algorithm>

#include "s3e.h"
#include "IwHashString.h"

#include "Error.hpp"

AudioManager::Effect::Effect(const std::string& file)
	: m_hash(0)
	, m_data(NULL)
	, m_specification(NULL) {
	m_hash = IwHashString(file.c_str());

	m_data = CIwSoundWAV::Create(file.c_str());
	if (m_data == NULL) {
		throw Error("Fail to load sound effect: %s", file.c_str());
	}

	try {
		m_specification = new CIwSoundSpec();
	} catch (...) {
		delete m_data;
		throw;
	}
	m_specification->SetData(m_data);
}

AudioManager::Effect::~Effect() {
	delete m_specification;
	delete m_data;
}

void AudioManager::Effect::Play() {
	m_specification->Play();
}

uint32 AudioManager::Effect::GetHash() const {
	return m_hash;
}

AudioManager::AudioManager() {
	IwSoundInit();
}

AudioManager::~AudioManager() {
	std::for_each(m_effects.begin(), m_effects.end(), ClearEffect());
	IwSoundTerminate();
}

void AudioManager::Update(float delta) {
	IwGetSoundManager()->Update();
}

void AudioManager::PlayMusic(const std::string& file, bool repeat) {
	if (s3eAudioIsCodecSupported(S3E_AUDIO_CODEC_MP3)) {
		s3eAudioPlay(file.c_str(), repeat ? 0 : 1);
	} else {
		throw Error("Mp3 codec is not supported");
	}
}

void AudioManager::StopMusic() {
	s3eAudioStop();
}

void AudioManager::PlayEffect(const std::string& file) {
	Effect* effect = NULL;
	EffectList::iterator found = std::find_if(m_effects.begin(), m_effects.end(),
		FindEffect(IwHashString(file.c_str())));
	if (found == m_effects.end()) {
		effect = new Effect(file);
		m_effects.push_back(effect);
	} else {
		effect = *found;
	}
	effect->Play();
}
