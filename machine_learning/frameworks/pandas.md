
https://jakevdp.github.io/PythonDataScienceHandbook/index.html

## basic

df.name

df.nunique or df."column_name".unique

df.replace

df.apply(pd.to_numeric) // convert columns to numeric

df.dropna

df.keys

df.select_dtypes

df.info

df.shape

df.dtypes

df.values

## Purging NaN and Inf

df.isna

df.fillna

df.isnf

## convert categorical to indicator

pd.get_dummies


## stats

df.corr

pct_change

pd.crosstab

df.describe

df.corrwith(another df)

df.rolling

df.resample

df.diff

df.median

df.mean

df.interpolate

df.groupby.describe

df.groupby.agg

https://stackoverflow.com/questions/19384532/get-statistics-for-each-group-such-as-count-mean-etc-using-pandas-groupby?rq=1

## rename

df.rename

df2.columns = ['A', 'B']  

## time

Timestamp, Period, Timedelta

pd.date_range, pd.period_range, pd.timedelta_range

df.asfreq

df.shift - shift data

df.tshift - shift index

## custom data reader

pandas_datareader

## compare or merge dataframes

df.combine

df.align

df.interpolate

df.merge(how = '')

df1['ColumnName'].isin(df2['ColumnName']).value_counts()

df1.where(df1.values==df2.values).notna()

set(df1['c2']).intersection(set(df2['c2']))

## split x y

y = df['label']
X = df.drop('label',axis=1)

y = df['label']
X = df.loc[:, df.columns != 'label']

## extract columns and rename

df = df[["c1", "c2"]]
df.columns = ["c1", any_name]

## index

df['Datetime'] = pd.to_datetime(df['date'] + ' ' + df['time'])
df = df.set_index('Datetime')
https://stackoverflow.com/questions/27032052/how-do-i-properly-set-the-datetimeindex-for-a-pandas-datetime-object-in-a-datafr

## plotting

https://stackoverflow.com/questions/37414008/plotting-multiple-dataframes-using-pandas-functionality

pandas.plotting.autocorrelation_plot()

https://pandas.pydata.org/docs/reference/api/pandas.plotting.scatter_matrix.html

https://pandas.pydata.org/docs/reference/api/pandas.plotting.lag_plot.html

# Misc

https://stackoverflow.com/questions/14262433/large-data-workflows-using-pandas?rq=1


# tutor

https://pandastutor.com/
