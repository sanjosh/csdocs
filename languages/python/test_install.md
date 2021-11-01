
```
from venv import EnvBuilder
env = EnvBuilder(with_pip=True)
env.create(env_dir=tmp_path)
context = env.ensure_directories(tmp_path)

        subprocess.check_output(
        [
            context.env_exe,
            "-m",
            "pip",
            "install",
            str(wheelpath),
        ]
    )

    environ = os.environ.copy()
    environ["PLAYWRIGHT_BROWSERS_PATH"] = str(tmp_path)

    subprocess.check_output(
        [context.env_exe, "-m", "playwright", "install"], env=environ
    )
```

https://github.com/microsoft/playwright-python/blob/da1bd03b82316a246417b489b73ccd2cb6c8839a/tests/test_installation.py#L24

