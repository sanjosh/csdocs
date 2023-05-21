
# survey, jaiswal

It aims at embedding augmented versions of the same sample close to each other while trying to push away embeddings from different samples.

Pretext tasks are self-supervised tasks that act as an important strategy to learn
representations of the data using pseudolabels. These pseudolabels are generated
automatically based on the attributes found in the data. The learned model from the pretext
task can be used for any downstream tasks such as classification, segmentation, detection,
etc. in computer vision. Furthermore, pretext tasks can be designed for any kind of data
such as image, video, speech, signals, and so on. For a pretext task in contrastive
learning, the original image acts as an anchor, its augmented(transformed) version acts as
a positive sample, and the rest of the images in the batch or in the training data act as
negative samples.

Most of the commonly used pretext tasks are divided into four main categories: color
transformation, geometric transformation, context-based tasks, and cross-modal-based tasks.
These pretext tasks have been used in various scenarios based on the problem intended to be
solved.

Video : A video contains a sequence of semantically related frames. This implies that
frames that are nearby with respect to time are closely related and the ones that are far
away are less likely to be related. Intuitively, the motive for using such an approach is
solving a pretext task that allows the model to learn useful visual representations while
trying to recover the temporal coherence of a video. Here, a video with shuffled order in
the sequence of its image frames acts as a positive sample while all other videos in the
batch/dataset would be negative samples.


https://www.mdpi.com/2227-7080/9/1/2

# weng

https://lilianweng.github.io/lil-log/2021/05/31/contrastive-representation-learning.html

Triplet loss was originally proposed in the FaceNet (Schroff et al. 2015) paper and was used to learn face recognition of the same person at different poses and angles.

# SimCLR

It learns representations for visual inputs by maximizing agreement between differently augmented views of the same sample via a contrastive loss in the latent space.

# deepfindr youtube

https://www.youtube.com/watch?v=XpUKZEGWqbU

point clouds (voxel, multiview, permutation-invariant Neural net)

batch size needs to be more so you get more negative samples

