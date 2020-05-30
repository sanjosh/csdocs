
# Reverberation

1. sound travels at 343 metres/sec
2l reflection is distinguished if heard after 10 ms
3. if reflected sound arrives within 10 ms, it is combined with original sound.  These sounds can also produce comb filter effects
4. Reflected sound which arrives 20-50 ms later provides information on room size
5. Reflection arriving after 50 ms is tail of reverb

reverberation radius : place microphone at that distance from sound source where volume(diffuse sound).= volume(direct sound)
 
From https://www.sonible.com/blog/reverb-audio-production/

T60 : time it takes for sound pressure level to reduce by (subtract) 60 dB.  After 60 dB reduction, it becomes inaudible

Echo is detected 50 to 100 ms after original sound

Reverberation time is frequency dependent

Reverberation time (decay time) is proportional to room dimensions and inversely proportional to the amount of absorption present.

Rooms used for speech typically need a shorter reverberation time

Reverberation changes the perceived spectral structure of a sound but does not alter the pitch.

The concept of Reverberation Time implicitly supposes that the decay rate of the sound is exponential, so that the sound level diminishes regularly, at a rate of so many dB per second (dB is a log measure). It is not often the case in real rooms, depending on the disposition of reflective, dispersive and absorbing surfaces. 

The RT60 reverberation time measurement is defined in the ISO (https://en.wikipedia.org/wiki/ISO) 3382-1 standard for performance spaces, the ISO (https://en.wikipedia.org/wiki/ISO) 3382-2 standard for ordinary rooms, and the ISO (https://en.wikipedia.org/wiki/ISO) 3382-3 for open-plan offices, as well as the ASTM (https://en.wikipedia.org/wiki/ASTM) E2235 standard.

from https://en.wikipedia.org/wiki/Reverberation

In general, the more speech content there is to the sound, the lower the ideal reverberation time (https://www.sciencedirect.com/topics/engineering/reverberation-time).  

For classrooms and small lecture halls times at or below one second are preferred. 

Longer reverberation times (https://www.sciencedirect.com/topics/engineering/reverberation-time) are desirable for music; the ideal length depends on both the room size and the type of music. 

For light opera such as Gilbert and Sullivan, where understanding the complicated play of words is critical, a time of 1.0 to 1.2 seconds would not be too low.

 For a Mozart opera preferred reverberation times might range from 1.2 to 1.5 seconds. 

A Wagnerian opera is ideal in a 1.5 to 1.6 second room, and romantic symphonies sound best in a 1.7 to 2.1 second hall. 

For organ concerts and medieval chant, reverberation times between 2.5 and 3.5 seconds are not too long. For example, Chartres Cathedral has a 5 second reverberation time. 

Clearly there is no single reverberation time that is perfect for all uses of a given room. Variations between 5 and 10% from the ideal values are commonplace.

from https://www.sciencedirect.com/topics/engineering/reverberation

https://github.com/DavidDiazGuerra/gpuRIR

# Acoustic simulator

We use the image method to model the room impulse responses

In the image method, a real room is acoustically mirrored with respect to each wall, which results in grids of virtual rooms

J. Allen and D. Berkley, “Image method for efficiently simulating small-room acoustics

Kim, Generation of large-scale simulated utterances in virtual rooms to train deep-neural networks for far-field speech recognition


# Impulse response generator

https://pypi.org/project/pyroomacoustics/

https://github.com/ehabets/RIR-Generator

Emanuel Habets https://github.com/ehabets/RIR-Generator/blob/master/rir_generator.pdf

