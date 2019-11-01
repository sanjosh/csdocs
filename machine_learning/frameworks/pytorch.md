
# internals

http://blog.christianperone.com/2018/03/pytorch-internal-architecture-tour/

# Pytorch

## autograd

If we want to compute gradients with respect to some Tensor, then we set requires_grad=True when constructing that Tensor. Any PyTorch operations on that Tensor will cause a computational graph to be constructed, allowing us to later perform backpropagation through the graph

```
a = Variable
y = torch.sum(a ** 2)
y.backward
a.grad()
```

## core training

each of the variables is a PyTorch Variable

```
output_batch = model(train_batch)           # compute model output
loss = loss_fn(output_batch, labels_batch)  # calculate loss
optimizer.zero_grad()  # clear previous gradients
loss.backward()        # compute gradients of all variables wrt loss
optimizer.step()      # perform updates using calculated gradients
```

## GPU

Calling .cuda() on a model/Tensor/Variable sends it to the GPU. In order to train a model on the GPU, all the relevant parameters and Variables must be sent to the GPU using .cuda().

Sequential

```
model = torch.nn.Sequential(
          torch.nn.Linear(D_in, H),
          torch.nn.ReLU(),
          torch.nn.Linear(H, D_out),
        ).to(device)
```

## Custom NN modules

 
```
class MyNet(torch.nn.Module):
  def __init__()
  def forward()
```

## Dataset

```
class MyDataset(torch.utils.data.Dataset):
  def __init__()
  def __len__()
  def __getitem__()
```

## Dataloader

https://cs230-stanford.github.io/pytorch-getting-started.html
