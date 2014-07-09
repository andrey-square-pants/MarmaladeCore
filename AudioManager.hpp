#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <list>
#include <string>
#include <functional>

#include "IwSound.h"

#include "Core.hpp"

class IAudio {
public:
	virtual ~IAudio() {
	}

	virtual void PlayEffect(const std::string& file) = 0;

	virtual void PlayMusic(const std::string& file, bool repeat) = 0;
	virtual void StopMusic() = 0;
};

class AudioManager : public IAudio, public IUpdateable {
public:
	AudioManager();
	virtual ~AudioManager();

	virtual void Update(float delta);

	virtual void PlayEffect(const std::string& file);

	virtual void PlayMusic(const std::string& file, bool repeat);
	virtual void StopMusic();

private:
	class Effect {
	public:
		Effect(const std::string& file);
		virtual ~Effect();

		void Play();
		uint32 GetHash() const;

	private:
		uint32 m_hash;
		CIwSoundData* m_data;
		CIwSoundSpec* m_specification;

		DISABLE_COPY(Effect);
	};

	typedef std::list<Effect*> EffectList;

	class ClearEffect : public std::unary_function<Effect*, void> {
	public:
		void operator()(Effect* effect) const {
			delete effect;
		}
	};

	class FindEffect : public std::unary_function<const Effect*, bool> {
	public:
		FindEffect(uint32 hash)
			: m_hash(hash) {
		}

		bool operator()(const Effect* effect) const {
			return (effect->GetHash() == m_hash);
		}

	private:
		uint32 m_hash;
	};

private:
	EffectList m_effects;

	DISABLE_COPY(AudioManager);
};

#endif
