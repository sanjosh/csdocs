
# pytorch

## model summary

print(model)

use torchinfo

```
print(model._get_state_dict)
```

## find bottleneck

```
python -m torch.utils.bottleneck
```

https://pytorch.org/docs/stable/bottleneck.html

## disable GPU scan

```
import torch
torch.cuda.is_available = lambda: False
```

## freeze and optimize model

https://pytorch.org/tutorials/beginner/Intro_to_TorchScript_tutorial.html

```
scripted_module = torch.jit.script(model.eval())
frozen_module = torch.jit.freeze(scripted_module, preserved_attrs=["version"])
model = torch.jit.optimize_for_inference(frozen_module)
```

## quantization

https://pytorch.org/docs/stable/torch.quantization.html

https://pytorch.org/docs/stable/quantization.html

```
model_int8 = torch.quantization.quantize_dynamic(
        model, 
        {torch.nn.Linear, torch.nn.LSTM},  
        dtype=torch.qint8)
```

## distillation

https://github.com/SforAiDl/KD_Lib

## number of threads for pytorch

```
torch.jit.set_num_threads
```

https://pytorch.org/docs/stable/notes/cpu_threading_torchscript_inference.html

## pruning

```
 parameters_to_prune = (
            (model.rnn, 'weight_hh_l0'),
            (model.linear, 'weight'),
        )

        prune.global_unstructured(
            parameters_to_prune,
            pruning_method=prune.L1Unstructured,
            amount=0.2,
        )
```

https://pytorch.org/tutorials/intermediate/pruning_tutorial.html

## tensorRT

## ONNX 

https://onnxruntime.ai/docs/#onnx-runtime-for-inferencing

https://onnxruntime.ai/docs/tutorials/accelerate-pytorch/pytorch.html
