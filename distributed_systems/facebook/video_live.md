
# scaling video 2017

1. RTMP
2. h264 - video
3. aac - audio

generate streamId (for hashing), security token, URI

broadcaster →  POP Proxygen →  Encoding host

Encoding host : central 

authenticate, associate host to stream, generate encoding, generate DASH output, store media for VOD

create 1 second DASH segments

adaptive bitrate

thundering herd - cache blocking timeout

new feature: two people talking at same time 

everstore to store videos

## REF

1. https://dl.acm.org/citation.cfm?doid=3132747.3132775
2. https://www.youtube.com/watch?v=IO4teCbHvZw&pbjreload=10
3. https://www.infoq.com/podcasts/sachin-kulkarni-facebook-live/

# Picture coding symposium PCS 2021 delivering video

Realtime calling on specialized hardware device like Portal

Portal = Android device, hi-res camera, wifi only, plugged-in (not low power)

## hardware encoder optimization

Android Mediacodec provides 2x API for encoder/decoder
1. bytebuffer
2. texture (allows opengl es rendering)

texture unlocks perf
1. desync cpu with GPU - higher fps
2. color conversion and rescaling done on GPU
3. save mem bandwidth avoid round trip between CPU & gpu

hardware encoder optimizations (as opposed to webrtc software)

video resolution and framerate scaler
1. video scaler algo inputs : bitrate, cpu usage, qp distribution, motion level
1. resolution and frame rate closely related

do initial probing, mid-call probing, codec adaptation

there is remote client diversity and large groups : simulcast support

## ROI encoding

do ROI encoding (region of interest) to enhance some video areas
1. put more bits around the face
2. challenges : negative effect on rate control, encoder support is broken

## latency reduction 

how to reduce audio latency : 
1. reduce packet size - send more packet size vs frame size; 
2. switch from java audio to AAudio
3. disable audio video sync

## measurement

how to measure impact (cannot rely on user experimentation solely)
1. offline quality eval (encapp tool github/johanblome/encapp, rtp parsing (github/chemag/rtpcap)
2. lab testing : audio video injection and recording; replace mic & camera signal with known signal; record signal from messenger stack.
3. field metrics : video referential (VMAF, SSIM, PSNR) ; non-referential (brave), Brisque, audio referential VISQOL)

## benefit cost model to determine encoder algo

Adaptive bitrate streaming (ABR) can reduce buffering

advanced code (VP9) has better compression than H264 but requires more compute

not enough compute to produce advanced codec for all videos

small percent of all videos generate majority watch time (zipf)

model : spend X cpu unit to reduce Y MB of bandwidth for N users

encoder worker farm decides priority = benefit/cost
1. benefit = (BD rate at specific quality level * effective predicted watch time)
1. cost = compute cost of encoding job

only predict for next hour.

predicting watch time using ML : 
1. video features : past watch time, duration, post type (live, stories, vod)
2. user features : how much time user's other videos are watched, potential audience time

use two different models
1. when video uploaded
2. when video has been watched

better prediction using 2 separate models since past watch time not available on newly uploaded videos

## video quality metrics

1. varying cost of mobile data
1. diverse content
1. maintain minimum quality bar
1. minimize wasted bytes
1. minimize cpu pressure

bitrate vs FB-MOS curve

questions
1. max end-to-end latency in live streaming:  ITU defines 150 ms or lower one-way, above 400 is bad.
2. frame rate & resolution for Portal for up-scaling and down-scaling : 30 fps, 720P res.  Only downscaling, no upscaling
3. ROI encoding : compliment it with tracking, prediction and resalency


https://engineering.fb.com/2021/04/05/video-engineering/how-facebook-encodes-your-videos/

https://engineering.fb.com/video/pcs2021/
