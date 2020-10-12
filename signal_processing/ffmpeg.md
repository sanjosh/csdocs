
# tutorial

https://github.com/leandromoreira/ffmpeg-libav-tutorial

# File formats

## Container

https://en.wikipedia.org/wiki/Digital_container_format

https://video.stackexchange.com/questions/9942/mp4-codec-or-container

Container can have multiple streams (audio, video, subtitles).  Usually, video stream is 1 but audio can be many (mono, stereo)

https://video.stackexchange.com/questions/20933/can-video-have-multiple-streams-like-it-has-2-audio-streams

## Audio formats

https://www.nch.com.au/acm/formats.html

## Video formats

https://en.wikipedia.org/wiki/Comparison_of_video_container_formats

### Bitrate

It can be 8-bit, 16-bit, VBR (variable bitrate)

### Sample rate

    CD quality : 44.1 KHz
    TV/DVD quality : 48 KHz
    Speech only : 32 KHz
    AM radio : 22.05 KHz

Sample rate is the attribute of a stream in the container.   Use "ffmpeg -show-streams" to obtain it https://stackoverflow.com/questions/18128727/how-to-detect-audio-sampling-rate-with-avprobe-ffprobe)

 
### Frames per second (FPS for video)


FPS can be different from sample rate, if video is not PCM

    https://stackoverflow.com/questions/19589496/frame-rate-vs-sample-rate
    https://askubuntu.com/questions/110264/how-to-find-frames-per-second-of-any-video-file

### File size

    https://stackoverflow.com/questions/13556265/how-to-calculate-audio-file-size

# ffmpeg

Streams from multiple files can be combined

    "0" is first file, "1" is first file
    "0:a" => 0 is first file, 'a' is all audio streams, "v" is video streams
    "0:1" => first file, second stream

https://ffmpeg.org/ffmpeg.html#Stream-selection


## remove initial print

-hide_banner

## print info

ffmpeg -i <input_file> -f null /dev/null

    https://stackoverflow.com/questions/20323640/ffmpeg-deocde-without-producing-output-file

## get frame rate of video

ffprobe <filename.mp4> -v 0 -select_streams v -print_format flat -show_entries stream=r_frame_rate

## Insert subtitle file into video

ffmpeg -i <input_video.mp4> -strict -2 -vf subtitles=<subtitle.ass> <output_video.mp4>

## Use ffmpeg to convert vtt to ass format

## Extract only audio

Use "-vn" option to remove video output; use "-f mp4" to set output format

ffmpeg -i input-video.avi -sn -vn -acodec copy -f mp4 output-audio.mp4

    https://stackoverflow.com/questions/9913032/ffmpeg-to-extract-audio-from-video
    https://stackoverflow.com/questions/20295398/ffmpeg-clip-audio-interval-with-starting-and-end-time

## Get video duration

ffprobe <filename.mp4> -v 0 -sexagesimal -select_streams v -print_format flat -show_entries format=duration

    https://superuser.com/questions/650291/how-to-get-video-duration-in-seconds
    http://trac.ffmpeg.org/wiki/FFprobeTips

## Audio duration can be different from video duration

This can happen for a variety of reasons

If there are gaps in the video, apply audio filter which "stretches/squeezes" the audio stream to match the timestamps,

ffmpeg -i input.mp4 -af aresample=async=1 -vn output.wav

    https://stackoverflow.com/questions/29261283/extract-audio-from-video-with-ffmpeg-but-not-the-same-duration?rq=1
    https://stackoverflow.com/questions/41136242/duration-of-source-video-and-subtracted-audio-are-different
    https://video.stackexchange.com/questions/15581/video-converted-by-ffmpeg-has-a-different-duration-why

Use "apad" filter to pad with silence

 -filter_complex "[0:1]apad"

and use

 -shortest 

    https://superuser.com/questions/871084/ffmpeg-extract-audio-with-exact-frame-length-of-video
    https://www.ffmpeg.org/ffmpeg-filters.html#apad

## Find number of audio streams

ffprobe -i yourFile.mp4 -show_entries stream=channels -select_streams a:0 -of compact=p=0:nk=1 -v 0

    https://stackoverflow.com/questions/47905083/how-to-check-number-of-channels-in-my-audio-wav-file-using-ffmpeg-command

## Get audio sample rate

select audio stream

 ffprobe  -show_streams -select_streams a <filename.mp4> -hide_banner

## Copy all audio streams

Use

-map 0 

https://stackoverflow.com/questions/37820083/ffmpeg-not-copying-all-audio-streams

## Output format

Use "-f" option

ffmpeg -i input.mp4 -f wav output.wav

https://stackoverflow.com/questions/9869120/ffmpeg-output-file-format-with-no-extension
