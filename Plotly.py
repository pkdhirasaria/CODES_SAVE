Plotyly

import plotly.graph_objects as go
fig = go.Figure()
df['color'] = np.where(df['effect'] <0,'red','blue')
fig.add_trace(go.Bar(x=df['effect'],y=df['kpi'],orientation='h',text=df['effect'],marker_color=df['color'],hovertext=df['actual']))
fig.update_layout(height=1500,yaxis={'categoryorder':'total ascending'},title='Fine Ore Parameter Effect')
fig.update_traces(texttemplate='%{text:.2s}',textposition='outside')
fig.show()



import plotly.express as px
import plotly.graph_objects as go
for v in ['count', 'mean', 'std', 'min', '25%', '50%', '75%', 'max']:
    g = old_describe[old_describe['index'] == v]
    h = bm_describe[bm_describe['index'] == v]
    g = g.T.reset_index()
    h = h.T.reset_index()
    g.columns = g.loc[0]
    h.columns = h.loc[0]
    g = g[1:]
    h = h[1:]
    # print(h,g)
    g = g[g['index'] != 'PIIntTSTicks']
    h = h[h['index'] != 'PIIntTSTicks']
    t1 = go.Bar(x=h['index'],y=h[v],name='BALL_MILLING_Test_Draft_Single',text=h[v])
    t2 = go.Bar(x=g['index'],y=g[v],name='bod_armap_ball_mill',text=g[v])
    data = [t1,t2]
    fig = go.Figure(data=data)
    fig.update_layout(barmode='group',title=v,height=1000)
    fig.update_traces(texttemplate='%{text:.2s}',textposition='outside')
    fig.show()
