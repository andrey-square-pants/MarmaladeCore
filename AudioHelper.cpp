#include "AudioHelper.hpp"

#include <algorithm>

#include "s3e.h"
#include "IwHashString.h"

#include "Error.hpp"

AudioHelper::Effect::Effect(const std::string& name)
	: m_hash(0)
	, m_data(NULL)
	, m_specification(NULL) {
	m_hash = IwHashString(name.c_str());

	m_data = CIwSoundWAV::Create(name.c_str());
	if (m_data == NULL) {
		throw Error("Fail to load sound effect: %s", name.c_str());
	}

	try {
		m_specification = new CIwSoundSpec();
	} catch (...) {
		delete m_data;
		throw;
	}
	m_specification->SetData(m_data);
}

AudioHelper::Effect::~Effect() {
	delete m_specification;
	delete m_data;
}

void AudioHelper::Effect::Play() {
	m_specification->Play();
}

uint32 AudioHelper::Effect::GetHash() const {
	return m_hash;
}

AudioHelper::AudioHelper() {
	IwSoundInit();
}

AudioHelper::~AudioHelper() {
	std::for_each(m_effects.begin(), m_effects.end(), ClearEffect());
	IwSoundTerminate();
}

void AudioHelper::Update(float delta) {
	IwGetSoundManager()->Update();
}

void AudioHelper::PlayMusic(const std::string& name, bool repeat) {
	if (s3eAudioIsCodecSupported(S3E_AUDIO_CODEC_MP3)) {
		s3eAudioPlay(name.c_str(), repeat ? 0 : 1);
	} else {
		throw Error("Mp3 codec is not supported");
	}
}

void AudioHelper::StopMusic() {
	s3eAudioStop();
}

void AudioHelper::PlayEffect(const std::string& name) {
	Effect* effect = NULL;
	EffectList::iterator found = std::find_if(m_effects.begin(), m_effects.end(),
		FindEffect(IwHashString(name.c_str())));
	if (found == m_effects.end()) {
		effect = new Effect(name);
		m_effects.push_back(effect);
	} else {
		effect = *found;
	}
	effect->Play();
}
