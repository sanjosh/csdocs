
# coverage metric

number of times actual is more than predicted

# quantile loss

To check if N percent of predictions are correct

# asymmetric loss

penalize over-prediction much more than under-prediction,

# code 

```
import numpy as np
import pandas as pd

def coverage_metric(df: pd.DataFrame) -> float:
    """
    Computes one-sided coverage: fraction of cases where predicted <= actual.
    Returns a value in [0,1].
    """
    return (df["predicted"] <= df["actual"]).mean()


def quantile_loss_metric(df: pd.DataFrame, tau: float = 0.9) -> dict:
    """
    Computes quantile (pinball) loss at quantile tau.
    Returns raw loss, normalized loss (by mean actual), and skill score vs baseline.
    """
    errors = df["actual"] - df["predicted"]
    loss = np.maximum(tau * errors, (tau - 1) * errors).mean()

    # normalization by mean actual
    norm_loss = loss / df["actual"].mean()

    # baseline: always predict mean(actual)
    baseline_pred = np.full_like(df["actual"], df["actual"].mean())
    base_err = df["actual"] - baseline_pred
    baseline_loss = np.maximum(tau * base_err, (tau - 1) * base_err).mean()
    skill = 1 - loss / baseline_loss if baseline_loss > 0 else np.nan

    return {"raw": loss, "normalized": norm_loss, "skill_score": skill}


def asymmetric_loss_metric(df: pd.DataFrame, alpha: float = 5.0) -> dict:
    """
    Computes asymmetric loss where over-prediction is penalized alpha times more than under-prediction.
    Returns raw loss, normalized loss (by mean actual), and skill score vs baseline.
    """
    over = np.maximum(df["predicted"] - df["actual"], 0)
    under = np.maximum(df["actual"] - df["predicted"], 0)
    loss = (alpha * over + under).mean()

    # normalization by mean actual
    norm_loss = loss / df["actual"].mean()

    # baseline: always predict mean(actual)
    baseline_pred = np.full_like(df["actual"], df["actual"].mean())
    over_b = np.maximum(baseline_pred - df["actual"], 0)
    under_b = np.maximum(df["actual"] - baseline_pred, 0)
    baseline_loss = (alpha * over_b + under_b).mean()
    skill = 1 - loss / baseline_loss if baseline_loss > 0 else np.nan

    return {"raw": loss, "normalized": norm_loss, "skill_score": skill}

```
